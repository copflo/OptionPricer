#include <fstream>
#include <sstream>

#include <mysql/cppconn/exception.h>
#include <mysql/cppconn/resultset.h>

#include "MySQLDatabase.h"


MySQLDatabase::MySQLDatabase(const sql::SQLString& host, const sql::SQLString& user, const sql::SQLString& passwd)
    : _driver(get_driver_instance())
    , _connection(_driver->connect(host, user, passwd))
{
    /* Connect to the MySQL marketdata database */
    _connection->setSchema("marketdata");

    _queryISIN.reset(_connection->prepareStatement(ISIN_QUERY));
    _importSecurity.reset(_connection->prepareStatement(INSERT_SECURITY));
    _importCurrency.reset(_connection->prepareStatement(INSERT_CURRENCY));
    _importQuote.reset(_connection->prepareStatement(INSERT_QUOTE));
}

MySQLDatabase::~MySQLDatabase()
{
}

void MySQLDatabase::importSecurity(const std::string& isin, const std::string& name)
{
    _importSecurity->setString(1, sql::SQLString(isin));
    _importSecurity->setString(2, sql::SQLString(name));
    _importSecurity->executeUpdate();
}

void MySQLDatabase::importSecurities(const std::map<std::string, std::string>& securities)
{
    for (auto&& pair : securities) {
        importSecurity(pair.first, pair.second);
    }
}

void MySQLDatabase::importCurrency(const std::string& currency)
{
    _importCurrency->setString(1, sql::SQLString(currency));
    _importCurrency->executeUpdate();
}

void MySQLDatabase::importSecuritiesFromCSVFile(const std::string& file)
{
    std::ifstream csvFile(file);
    if (!csvFile.is_open()) {
        throw std::runtime_error(file + " not found");
    }

    std::string line;
    while (std::getline(csvFile, line)) {
        try {
            std::istringstream buffer(line);

            std::string isin;
            std::getline(buffer, isin, ',');

            std::string name;
            std::getline(buffer, name, ',');

            importSecurity(isin, name);
        }
        catch(const sql::SQLException& ex) {
            std::cerr << ex.what() << std::endl;
        }
        catch (const std::exception& ex) {
            std::cerr << ex.what() << std::endl;
        }
    }
}

void MySQLDatabase::importQuotesFromCSVFile(const std::string& stockExchange, const std::string& file)
{
    std::ifstream csvFile(file);
    std::string line;

    std::getline(csvFile, line); //header

    while (std::getline(csvFile, line)) {
        try {
            std::istringstream buffer(line);

            std::string isin;
            std::getline(buffer, isin, ',');

            std::string date;
            std::getline(buffer, date, ',');

            std::string opening;
            std::getline(buffer, opening, ',');

            std::string highest;
            std::getline(buffer, highest, ',');

            std::string lowest;
            std::getline(buffer, lowest, ',');

            std::string closing;
            std::getline(buffer, closing, ',');

            std::string adjClosing;
            std::getline(buffer, adjClosing, ',');

            std::string volume;
            std::getline(buffer, volume);

            importQuoteFromISIN(isin,
                                date,
                                stockExchange,
                                std::stod(opening),
                                std::stod(highest),
                                std::stod(lowest),
                                std::stod(closing),
                                std::stod(adjClosing),
                                std::stoi(volume)
                               );
        }
        catch (const sql::SQLException& ex) {
            std::cerr << ex.what() << std::endl;
        }
        catch (const std::exception& ex) {
            std::cerr << ex.what() << std::endl;
        }
    }
}

void MySQLDatabase::importQuoteFromISIN(const std::string& isin,
                                        const std::string& date,
                                        const std::string& stockExchange,
                                        double             opening,
                                        double             highest,
                                        double             lowest,
                                        double             closing,
                                        double             adjClosing,
                                        int                volume)
{
    _importQuote->setString(1, isin);
    _importQuote->setDateTime(2, date);
    _importQuote->setString(3, stockExchange);
    _importQuote->setDouble(4, opening);
    _importQuote->setDouble(5, highest);
    _importQuote->setDouble(6, lowest);
    _importQuote->setDouble(7, closing);
    _importQuote->setDouble(8, adjClosing);
    _importQuote->setInt(9, volume);

    _importQuote->executeUpdate();
}

void MySQLDatabase::importQuoteFromSecName(const std::string& name,
                                           const std::string& date,
                                           const std::string& stockExchange,
                                           double             opening,
                                           double             highest,
                                           double             lowest,
                                           double             closing,
                                           double             adjClosing,
                                           int                volume)
{
    _queryISIN->setString(1, name);
    std::unique_ptr<sql::ResultSet> result(_queryISIN->executeQuery());

    if (result->rowsCount() == 0) {
        throw std::runtime_error(name + " is not a registered security");
    }

    importQuoteFromISIN(result->getString(1),
                        date,
                        stockExchange,
                        opening,
                        highest,
                        lowest,
                        closing,
                        adjClosing,
                        volume);
}

double MySQLDatabase::vVolatility(const std::string& security,
                                  const std::string& stockExchange,
                                  int                nbDays,
                                  const std::string& startDate,
                                  const std::string& endDate)
{
    std::string query;
    query.append(" select stddev_samp(ln(Q2.CLOSING / Q1.CLOSING)) as VOLATILITY")
         .append(" from  QUOTES Q2")
         .append(" join  (select ISIN, TRADING_DATE, MARKET_PLACE, CLOSING")
         .append(       " from   QUOTES")
         .append(       " where  ISIN = (select ISIN")
         .append(                      " from   SECURITIES")
         .append(                      " where  SNAME = \"" + security + "\")")
         .append(          " and MARKET_PLACE = \"" + stockExchange + "\"");

    if (!startDate.empty()) {
        query.append(      " and TRADING_DATE >= str_to_date('" + startDate + "', '%d/%m/%y')");
    }
    if (!endDate.empty()) {
        query.append(      " and TRADING_DATE < str_to_date('" + endDate + "', '%d/%m/%y')");
    }
    query.append(") as Q1");

    query.append(" on  Q2.ISIN = Q1.ISIN")
         .append(" and Q2.MARKET_PLACE = Q1.MARKET_PLACE")
         .append(" and Q2.TRADING_DATE = (select min(TRADING_DATE)")
         .append(                       " from   QUOTES")
         .append(                       " where  TRADING_DATE > Q1.TRADING_DATE")
         .append(                          " and ISIN = Q1.ISIN")
         .append(                          " and MARKET_PLACE = Q1.MARKET_PLACE)");

    std::unique_ptr<sql::Statement> stmt(_connection->createStatement());
    std::unique_ptr<sql::ResultSet> result(stmt->executeQuery(query));

    return result->getDouble(1) * nbDays;
}

std::vector<double> MySQLDatabase::vCloseQuotes(const std::string& security,
                                                const std::string& stockExchange,
                                                const std::string& startDate,
                                                const std::string& endDate)
{
    return std::vector<double>();
}

std::vector<Quote> MySQLDatabase::vQuotes(const std::string& security, const std::string& stockExchange, const std::string& startDate, const std::string& endDate)
{
    return std::vector<Quote>();
}
