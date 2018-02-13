#include "options/AmericanOption.h"
#include "options/AssetOrNothingOption.h"
#include "options/EuropeanOption.h"

#include "Factory.h"


template<class Opt>
class PathIndependentOptionFactory
{
public:
    template<class UI>
    static Opt* build(const UI& ui);
};


template<class Opt>
template<class UI>
Opt* PathIndependentOptionFactory<Opt>::build(const UI& ui)
{
    return new Opt(ui.nature(), ui.maturity(), ui.strike());
}

template<>
template<class UI>
AmericanOption* Factory<AmericanOption>::build(const UI& ui)
{
    return PathIndependentOptionFactory<AmericanOption>::build(ui);
}

template<>
template<class UI>
AssetOrNothingOption* Factory<AssetOrNothingOption>::build(const UI& ui)
{
    return PathIndependentOptionFactory<AssetOrNothingOption>::build(ui);
}

template<>
template<class UI>
EuropeanOption* Factory<EuropeanOption>::build(const UI& ui)
{
    return PathIndependentOptionFactory<EuropeanOption>::build(ui);
}
