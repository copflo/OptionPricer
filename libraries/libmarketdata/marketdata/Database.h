#ifndef Database_h
#define Database_h

#include <map>
#include <string>
#include <vector>

#include "Quote.h"


class Database
{
public:
            Database ();
    virtual ~Database();

    double volatility(const std::string& security,
                      const std::string& stockExchange,
                      int                nbDays,
                      const std::string& startDate = "",
                      const std::string& endDate = "");

    std::vector<double> closeQuotes(const std::string& security,
                                    const std::string& stockExchange,
                                    const std::string& startDate = "",
                                    const std::string& endDate = "");

    std::vector<Quote> quotes(const std::string& security,
                              const std::string& stockExchange,
                              const std::string& startDate = "",
                              const std::string& endDate = "");

    virtual void importSecurity(const std::string& isin, const std::string& name) = 0;
    virtual void importSecurities(const std::map<std::string, std::string>& securities) = 0;

    virtual void importQuote(const Quote& quote) = 0;
    virtual void importQuotes(const std::vector<Quote>& quotes) = 0;
    virtual void importQuoteFromISIN(const std::string& isin,
                                     const std::string& date,
                                     const std::string& stockExchange,
                                     double             opening,
                                     double             highest,
                                     double             lowest,
                                     double             closing,
                                     double             adjClosing,
                                     int                volume) = 0;
    virtual void importQuoteFromSecName(const std::string& name,
                                        const std::string& date,
                                        const std::string& stockExchange,
                                        double             opening,
                                        double             highest,
                                        double             lowest,
                                        double             closing,
                                        double             adjClosing,
                                        int                volume) = 0;

    virtual void importCurrency(const std::string& currency) = 0;
    virtual void importCurrencies(const std::vector<std::string>& currencies) = 0;

protected:
    virtual double vVolatility(const std::string& security,
                               const std::string& stockExchange,
                               int                nbDays,
                               const std::string& startDate,
                               const std::string& endDate) = 0;

    virtual std::vector<double> vCloseQuotes(const std::string& security,
                                             const std::string& stockExchange,
                                             const std::string& startDate,
                                             const std::string& endDate) = 0;

    virtual std::vector<Quote> vQuotes(const std::string& security,
                                       const std::string& stockExchange,
                                       const std::string& startDate,
                                       const std::string& endDate) = 0;
};


#endif // Database_h
