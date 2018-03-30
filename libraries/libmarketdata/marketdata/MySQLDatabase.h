#ifndef MySQLDatabase_h
#define MySQLDatabase_h

#include <memory>

#include <mysql/mysql_connection.h>
#include <mysql/cppconn/driver.h>
#include <mysql/cppconn/prepared_statement.h>

#include "Database.h"


class MySQLDatabase
    : public Database
{
public:
            MySQLDatabase (const sql::SQLString& host,
                           const sql::SQLString& user,
                           const sql::SQLString& passwd);

    virtual ~MySQLDatabase();

    virtual void importSecurity(const std::string& isin, const std::string& name);

    virtual void importSecurities(const std::map<std::string, std::string>& securities);

    virtual void importCurrency(const std::string& currency);

    virtual void importSecuritiesFromCSVFile(const std::string& file);

    virtual void importQuotesFromCSVFile(const std::string& stockExchange,
                                         const std::string& file);

    virtual void importQuoteFromISIN(const std::string& isin,
                                     const std::string& date,
                                     const std::string& stockExchange,
                                     double             opening,
                                     double             highest,
                                     double             lowest,
                                     double             closing,
                                     double             adjClosing,
                                     int                volume);

    virtual void importQuoteFromSecName(const std::string& name,
                                        const std::string& date,
                                        const std::string& stockExchange,
                                        double opening,
                                        double highest,
                                        double lowest,
                                        double closing,
                                        double adjClosing,
                                        int volume);

protected:
    virtual double vVolatility(const std::string& security,
                               const std::string& stockExchange,
                               int nbDays,
                               const std::string& startDate,
                               const std::string& endDate);

    virtual std::vector<double> vCloseQuotes(const std::string& security,
                                             const std::string& stockExchange,
                                             const std::string& startDate,
                                             const std::string& endDate);

    virtual std::vector<Quote> vQuotes(const std::string& security,
                                       const std::string& stockExchange,
                                       const std::string& startDate,
                                       const std::string& endDate);

private:
    sql::Driver* _driver;
    std::unique_ptr<sql::Connection> _connection;

    std::unique_ptr<sql::PreparedStatement> _queryISIN;
    std::unique_ptr<sql::PreparedStatement> _importSecurity;
    std::unique_ptr<sql::PreparedStatement> _importQuote;
    std::unique_ptr<sql::PreparedStatement> _importCurrency;
};


#endif // MySQLDatabase_h
