#include "SQLDatabase.h"


const std::string MySQLDatabase::ISIN_QUERY = "select ISIN from SECURITIES where SNAME = ?";
const std::string MySQLDatabase::INSERT_SECURITY = "insert into SECURITIES values(?, ?)";
const std::string MySQLDatabase::INSERT_CURRENCY = "insert into CURRENCIES values(?)";
const std::string MySQLDatabase::INSERT_QUOTE = "insert into QUOTES values(?, str_to_date(?, '%d/%m/%y'), ?, ?, ?, ?, ?, ?, ?)";

const std::string MySQLDatabase::VOLATILITY = std::string("select stddev_samp(ln(Q2.ADJ_CLOSING / Q1.ADJ_CLOSING)) ")
                                                        + "from QUOTES Q2 "
                                                        + "join (select ISIN, TRADING_DATE, MARKET_PLACE, ADJ_CLOSING "
                                                        +       "from QUOTES "
                                                        +       "where ISIN = (select ISIN "
                                                        +                     "from SECURITIES "
                                                        +                     "where SNAME = ?) "
                                                        +       "and MARKET_PLACE = ?) as Q1 "
                                                        + "on  Q2.ISIN = Q1.ISIN "
                                                        + "and Q2.MARKET_PLACE = Q1.MARKET_PLACE "
                                                        + "and Q2.TRADING_DATE = (select min(TRADING_DATE) "
                                                        +                        "from   QUOTES "
                                                        +                        "where  TRADING_DATE > Q1.TRADING_DATE "
                                                        +                        "and ISIN = Q1.ISIN "
                                                        +                        "and MARKET_PLACE = Q1.MARKET_PLACE)";
