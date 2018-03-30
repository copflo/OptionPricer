#ifndef QUOTESIMPORT_H
#define QUOTESIMPORT_H

#include "Database.h"


template<class Formatter>
class QuotesImport
{
public:
    static void importSecurities(Database& db, const std::string& file) = 0;
}


#endif // QUOTESIMPORT_H
