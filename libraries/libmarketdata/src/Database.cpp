#include "Database.h"


Database::Database()
{
}

Database::~Database()
{
}

double Database::volatility(const std::string& security,
                            const std::string& stockExchange,
                            int                nbDays,
                            const std::string& startDate,
                            const std::string& endDate)
{
    return vVolatility(security, stockExchange, nbDays, startDate, endDate);
}

std::vector<double> Database::closeQuotes(const std::string& security,
                                          const std::string& stockExchange,
                                          const std::string& startDate,
                                          const std::string& endDate)
{
    return vCloseQuotes(security, stockExchange, startDate, endDate);
}

std::vector<Quote> Database::quotes(const std::string& security,
                                    const std::string& stockExchange,
                                    const std::string& startDate,
                                    const std::string& endDate)
{
    return vQuotes(security, stockExchange, startDate, endDate);
}
