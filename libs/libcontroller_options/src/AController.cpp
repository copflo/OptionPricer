#include "AController.h"
#include "Labels.h"


AController::AController(std::map<AController::key, AController::pricingFunc>&& pricingMap)
    : _pricingMap(pricingMap)
{
}

AController::~AController()
{
}

const std::map<std::string, std::vector<std::string>>& AController::availableModels()
{
    static const std::map<std::string, std::vector<std::string>> _availableModels{
            {
                Labels::Options::AMERICAN,
                { Labels::Models::BINOMIAL_TREE }
            },

            {
                Labels::Options::ASSET_OR_NOTHING,
                { Labels::Models::BLACK_SCHOLES, Labels::Models::BLACK_SCHOLES_MC }
            },

            {
                Labels::Options::CASH_OR_NOTHING,
                { Labels::Models::BLACK_SCHOLES, Labels::Models::BLACK_SCHOLES_MC}
            },

            {
                Labels::Options::EUROPEAN,
                { Labels::Models::BLACK_SCHOLES, Labels::Models::BLACK_SCHOLES_MC, Labels::Models::BINOMIAL_TREE }
            },

            {
                Labels::Options::ASIAN,
                { Labels::Models::BLACK_SCHOLES_MC }
            },

            {
                Labels::Options::BARRIER,
                { Labels::Models::BLACK_SCHOLES_MC }
            },

            {
                Labels::Options::LOOKBACK,
                { Labels::Models::BLACK_SCHOLES_MC }
            }
        };
    return _availableModels;
}
