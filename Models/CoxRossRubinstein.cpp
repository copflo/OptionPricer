#include "CoxRossRubinstein.h"

double CoxRossRubinstein::binomialValue(double riskfreeRate, double p, double upSpot, double downSpot)
{
    return (p * upSpot + (1. - p) * downSpot) / (1. + riskfreeRate);
}

CoxRossRubinstein::CoxRossRubinstein(double up, double down, size_t nbSteps)
    : _up(up)
    , _down(-down)
    , _nbSteps(nbSteps)
{
    if ((_down < _up) == false) {
        throw std::runtime_error("Decrease coefficient must be greater than the increase one");
    }
}

CoxRossRubinstein::~CoxRossRubinstein()
{
}

double CoxRossRubinstein::price(double risklessRate, double currentSpot, const VanillaOption& option) const
{
    if ((_down < risklessRate) == false || (risklessRate < _up) == false) {
        throw std::runtime_error("Error in modelization: down < r < up is not respected");
    }

    return optionValue(option, risklessRate, neutralProba(risklessRate), currentSpot, 0);
}

double CoxRossRubinstein::neutralProba(double risklessRate) const
{
    return (risklessRate - _down) / (_up - _down);
}

double CoxRossRubinstein::optionValue(const VanillaOption& option, double risklessRate, double p, double currentSpot, size_t stepNo) const
{
    if (stepNo == _nbSteps) {
        return option.payoff(currentSpot);
    }

    const double upValue = optionValue(option, risklessRate, p, currentSpot * (1. + _up), stepNo + 1);
    const double downValue = optionValue(option, risklessRate, p, currentSpot * (1. + _down), stepNo + 1);

    const double binomial = binomialValue(risklessRate, p, upValue, downValue);
    if (option.style() == "European") {
        return binomial;
    }

    return fmax(binomial, option.payoff(currentSpot));
}
