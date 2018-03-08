#ifndef PRICINGMAPBUILDER_H
#define PRICINGMAPBUILDER_H

#include <map>
#include <functional>

#include "Labels.h"
#include "Pricer.h"


template<class Str>
struct PricingMapBuilder 
{
    template<class MktUI, class OptFactUI, class ModlFactUI>
    static std::map<std::pair<Str, Str>, std::function<double()>> build(const MktUI& mktUI, 
                                                                        const OptFactUI& optFactUI,
                                                                        const ModlFactUI& modlFactUI);
};


template<class Str>
template<class MktUI, class OptFactUI, class ModlFactUI>
std::map<std::pair<Str, Str>, std::function<double()>> PricingMapBuilder<Str>::build(const MktUI& mktUI, 
                                                                                     const OptFactUI& optFactUI,
                                                                                     const ModlFactUI& modlFactUI)
{
    return {
        {
            { Labels<Str>::Options::AMERICAN, Labels<Str>::Models::BINOMIAL_TREE },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<AmericanOption, BinomialTree>::price(mktUI,
                                                                   optFactUI.pathIndependentOptionUI(),
                                                                   modlFactUI.binomialTreeUI());
            }
        },

        {
            { Labels<Str>::Options::ASIAN, Labels<Str>::Models::BLACK_SCHOLES_MC },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<IAsianOption, BlackScholesMonteCarlo>::price(mktUI,
                                                                           optFactUI.asianOptionUI(),
                                                                           modlFactUI.blackScholesMcUI());
            }
        },

        {
            { Labels<Str>::Options::ASSET_OR_NOTHING, Labels<Str>::Models::BLACK_SCHOLES },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<AssetOrNothingOption, BlackScholes>::price(mktUI,
                                                                         optFactUI.pathIndependentOptionUI(),
                                                                         modlFactUI.blackScholesUI());
            }
        },

        {
            { Labels<Str>::Options::ASSET_OR_NOTHING, Labels<Str>::Models::BLACK_SCHOLES_MC },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<AssetOrNothingOption, BlackScholesMonteCarlo>::price(mktUI,
                                                                                   optFactUI.pathIndependentOptionUI(),
                                                                                   modlFactUI.blackScholesMcUI());
            }
        },

        {
            { Labels<Str>::Options::BARRIER, Labels<Str>::Models::BLACK_SCHOLES_MC },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<IBarrierOption, BlackScholesMonteCarlo>::price(mktUI,
                                                                             optFactUI.barrierOptionUI(),
                                                                             modlFactUI.blackScholesMcUI());
            }
        },

        {
            { Labels<Str>::Options::CASH_OR_NOTHING, Labels<Str>::Models::BLACK_SCHOLES },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<CashOrNothingOption, BlackScholes>::price(mktUI,
                                                                        optFactUI.cashOrNothingOptionUI(),
                                                                        modlFactUI.blackScholesUI());
            }
        },

        {
            { Labels<Str>::Options::CASH_OR_NOTHING, Labels<Str>::Models::BLACK_SCHOLES_MC },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<CashOrNothingOption, BlackScholesMonteCarlo>::price(mktUI,
                                                                                  optFactUI.cashOrNothingOptionUI(),
                                                                                  modlFactUI.blackScholesMcUI());
            }
        },

        {
            { Labels<Str>::Options::EUROPEAN, Labels<Str>::Models::BLACK_SCHOLES },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<EuropeanOption, BlackScholes>::price(mktUI,
                                                                   optFactUI.pathIndependentOptionUI(),
                                                                   modlFactUI.blackScholesUI());
            }
        },

        {
            { Labels<Str>::Options::EUROPEAN, Labels<Str>::Models::BLACK_SCHOLES_MC },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<EuropeanOption, BlackScholesMonteCarlo>::price(mktUI,
                                                                             optFactUI.pathIndependentOptionUI(),
                                                                             modlFactUI.blackScholesMcUI());
            }
        },

        {
            { Labels<Str>::Options::EUROPEAN, Labels<Str>::Models::BINOMIAL_TREE },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<EuropeanOption, BinomialTree>::price(mktUI,
                                                                   optFactUI.pathIndependentOptionUI(),
                                                                   modlFactUI.binomialTreeUI());
            }
        },

        {
            { Labels<Str>::Options::LOOKBACK, Labels<Str>::Models::BLACK_SCHOLES_MC },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<ILookbackOption, BlackScholesMonteCarlo>::price(mktUI,
                                                                              optFactUI.lookbackOptionUI(),
                                                                              modlFactUI.blackScholesMcUI());
            }
        }
    };
}


#endif // PRICINGMAPBUILDER_H