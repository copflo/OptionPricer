#ifndef ACONTROLLER_H
#define ACONTROLLER_H

#include <functional>
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "Labels.h"
#include "Pricer.h"


class AController
{
protected:
    typedef std::pair<std::string, std::string> key;
    typedef std::function<double()> pricingFunc;

protected:
    static const std::map<std::string, std::vector<std::string>>& availableModels();

    template<class MktUI, class OptFactUI, class ModlFactUI>
    static std::map<key, pricingFunc> buildPricingMap(const MktUI& mktUI,
                                                      const OptFactUI& optFactUI,
                                                      const ModlFactUI& modlFactUI);

protected:
    AController(std::map<key, pricingFunc>&& pricingMap);
    virtual ~AController();

protected:
    std::map<key, pricingFunc> _pricingMap;
};


template<class MktUI, class OptFactUI, class ModlFactUI>
std::map<AController::key, AController::pricingFunc> AController::buildPricingMap(const MktUI& mktUI,
                                                                                  const OptFactUI& optFactUI,
                                                                                  const ModlFactUI& modlFactUI)
{
    return {
        {
            { Labels::Options::AMERICAN, Labels::Models::BINOMIAL_TREE },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<AmericanOption, BinomialTree>::price(mktUI,
                                                                   optFactUI.pathIndependentOptionUI(),
                                                                   modlFactUI.binomialTreeUI());
            }
        },

        {
            { Labels::Options::ASIAN, Labels::Models::BLACK_SCHOLES_MC },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<IAsianOption, BlackScholesMonteCarlo>::price(mktUI,
                                                                           optFactUI.asianOptionUI(),
                                                                           modlFactUI.blackScholesMcUI());
            }
        },

        {
            { Labels::Options::ASSET_OR_NOTHING, Labels::Models::BLACK_SCHOLES },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<AssetOrNothingOption, BlackScholes>::price(mktUI,
                                                                         optFactUI.pathIndependentOptionUI(),
                                                                         modlFactUI.blackScholesUI());
            }
        },

        {
            { Labels::Options::ASSET_OR_NOTHING, Labels::Models::BLACK_SCHOLES_MC },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<AssetOrNothingOption, BlackScholesMonteCarlo>::price(mktUI,
                                                                                   optFactUI.pathIndependentOptionUI(),
                                                                                   modlFactUI.blackScholesMcUI());
            }
        },

        {
            { Labels::Options::BARRIER, Labels::Models::BLACK_SCHOLES_MC },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<IBarrierOption, BlackScholesMonteCarlo>::price(mktUI,
                                                                             optFactUI.barrierOptionUI(),
                                                                             modlFactUI.blackScholesMcUI());
            }
        },

        {
            { Labels::Options::CASH_OR_NOTHING, Labels::Models::BLACK_SCHOLES },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<CashOrNothingOption, BlackScholes>::price(mktUI,
                                                                        optFactUI.cashOrNothingOptionUI(),
                                                                        modlFactUI.blackScholesUI());
            }
        },

        {
            { Labels::Options::CASH_OR_NOTHING, Labels::Models::BLACK_SCHOLES_MC },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<CashOrNothingOption, BlackScholesMonteCarlo>::price(mktUI,
                                                                                  optFactUI.cashOrNothingOptionUI(),
                                                                                  modlFactUI.blackScholesMcUI());
            }
        },

        {
            { Labels::Options::EUROPEAN, Labels::Models::BLACK_SCHOLES },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<EuropeanOption, BlackScholes>::price(mktUI,
                                                                   optFactUI.pathIndependentOptionUI(),
                                                                   modlFactUI.blackScholesUI());
            }
        },

        {
            { Labels::Options::EUROPEAN, Labels::Models::BLACK_SCHOLES_MC },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<EuropeanOption, BlackScholesMonteCarlo>::price(mktUI,
                                                                             optFactUI.pathIndependentOptionUI(),
                                                                             modlFactUI.blackScholesMcUI());
            }
        },

        {
            { Labels::Options::EUROPEAN, Labels::Models::BINOMIAL_TREE },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<EuropeanOption, BinomialTree>::price(mktUI,
                                                                   optFactUI.pathIndependentOptionUI(),
                                                                   modlFactUI.binomialTreeUI());
            }
        },

        {
            { Labels::Options::LOOKBACK, Labels::Models::BLACK_SCHOLES_MC },
            [&mktUI, &optFactUI, &modlFactUI]() {
                return Pricer<ILookbackOption, BlackScholesMonteCarlo>::price(mktUI,
                                                                              optFactUI.lookbackOptionUI(),
                                                                              modlFactUI.blackScholesMcUI());
            }
        }
    };
}


#endif // ACONTROLLER_H
