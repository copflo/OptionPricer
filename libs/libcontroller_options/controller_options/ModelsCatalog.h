#ifndef MODELSCATALOG_H
#define MODELSCATALOG_H

#include <map>
#include <vector>

#include "Labels.h"


template<class Str>
class ModelsCatalog
{
private:
    static const std::map<Str, std::vector<Str>>& catalog();

public:
    static const std::vector<Str>& modelsFor(const Str& optionType);
};


template<class Str> 
const std::map<Str, std::vector<Str>>& ModelsCatalog<Str>::catalog()
{
    static const std::map<Str, std::vector<Str>> _catalog {
        {
            Labels<Str>::Options::AMERICAN,
            { Labels<Str>::Models::BINOMIAL_TREE }
        },

        {
            Labels<Str>::Options::ASSET_OR_NOTHING,
            { Labels<Str>::Models::BLACK_SCHOLES, Labels<Str>::Models::BLACK_SCHOLES_MC }
        },

        {
            Labels<Str>::Options::CASH_OR_NOTHING,
            { Labels<Str>::Models::BLACK_SCHOLES, Labels<Str>::Models::BLACK_SCHOLES_MC}
        },

        {
            Labels<Str>::Options::EUROPEAN,
            { Labels<Str>::Models::BLACK_SCHOLES, Labels<Str>::Models::BLACK_SCHOLES_MC, Labels<Str>::Models::BINOMIAL_TREE }
        },

        {
            Labels<Str>::Options::ASIAN,
            { Labels<Str>::Models::BLACK_SCHOLES_MC }
        },

        {
            Labels<Str>::Options::BARRIER,
            { Labels<Str>::Models::BLACK_SCHOLES_MC }
        },

        {
            Labels<Str>::Options::LOOKBACK,
            { Labels<Str>::Models::BLACK_SCHOLES_MC }
        }
    };
    return _catalog;
}

template<class Str>
const std::vector<Str>& ModelsCatalog<Str>::modelsFor(const Str& optionType) 
{
    return catalog().at(optionType);
}


#endif // MODELSCATALOG_H