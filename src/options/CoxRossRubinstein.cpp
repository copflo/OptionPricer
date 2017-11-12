#include <cmath>
#include <stdexcept>

#include "CoxRossRubinstein.h"


double CoxRossRubinstein::binomialValue(double r, double p, double upSpot, double downSpot)
{
    return (p * upSpot + (1. - p) * downSpot) / (1. + r);
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

double CoxRossRubinstein::neutralProba(double risklessRate) const
{
    return (risklessRate - _down) / (_up - _down);
}

double CoxRossRubinstein::optionValue(const AmericanOption& option, double risklessRate, double p, double currentSpot, size_t stepNo) const
{
    if (stepNo == _nbSteps) {
        return option.payoff(currentSpot);
    }

    const double upValue = optionValue(option, risklessRate, p, currentSpot * (1. + _up), stepNo + 1);
    const double downValue = optionValue(option, risklessRate, p, currentSpot * (1. + _down), stepNo + 1);
    return fmax(binomialValue(risklessRate, p, upValue, downValue), option.payoff(currentSpot));
}

double CoxRossRubinstein::optionValue(const EuropeanOption& option, double risklessRate, double p, double currentSpot, size_t stepNo) const
{
    if (stepNo == _nbSteps) {
        return option.payoff(currentSpot);
    }

    const double upValue = optionValue(option, risklessRate, p, currentSpot * (1. + _up), stepNo + 1);
    const double downValue = optionValue(option, risklessRate, p, currentSpot * (1. + _down), stepNo + 1);
    return binomialValue(risklessRate, p, upValue, downValue);
}
