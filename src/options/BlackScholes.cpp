#include <cmath>

#include "BlackScholes.h"
#include "math_functions.h"


BlackScholes::BlackScholes(const Volatility& vol)
    : _vol(vol)
{
}

BlackScholes::~BlackScholes()
{
}

double BlackScholes::price(double risklessRate, double spot, const EuropeanOption& option) const
{
    const double T = static_cast<double>(option.maturity()) / _vol.period();
    const auto ds = d1_d2(risklessRate, spot, option.getStrike(), T);
    const double d1 = ds.first;
    const double d2 = ds.second;

    if (option.isCall()) {
        return (spot * std_normal_cdf(d1)) - (option.getStrike() * exp(-risklessRate * T) * std_normal_cdf(d2));
    }

    return (option.getStrike() * exp(-risklessRate * T) * std_normal_cdf(-d2)) - (spot * std_normal_cdf(-d1));
}

double BlackScholes::price(double risklessRate, double currentSpot, const CashOrNothingOption& option) const
{
    const double T = static_cast<double>(option.maturity()) / _vol.period();
    const auto d2 = BlackScholes::d2(risklessRate, currentSpot, option.getStrike(), T);

    if (option.isCall()) {
        return exp(-risklessRate * T) * std_normal_cdf(d2) * option.rebate();
    }

    return exp(-risklessRate * T) * std_normal_cdf(-d2) * option.rebate();
}

double BlackScholes::price(double risklessRate, double currentSpot, const AssetOrNothingOption& option) const
{
    const double T = static_cast<double>(option.maturity()) / _vol.period();
    const double d1 = BlackScholes::d1(risklessRate, currentSpot, option.getStrike(), T);

    if (option.isCall()) {
        return currentSpot * std_normal_cdf(d1);
    }

    return currentSpot * std_normal_cdf(-d1);;
}

double BlackScholes::delta(double risklessRate, double currentSpot, const EuropeanOption& option) const
{
    const double T = static_cast<double>(option.maturity()) / _vol.period();
    const double d1 = BlackScholes::d1(risklessRate, currentSpot, option.getStrike(), T);

    if (option.isCall()) {
        return std_normal_cdf(d1);
    }

    return std_normal_cdf(d1) - 1.;
}

double BlackScholes::vega(double risklessRate, double currentSpot, const EuropeanOption& option) const
{
    const double T = static_cast<double>(option.maturity()) / _vol.period();
    const double d1 = BlackScholes::d1(risklessRate, currentSpot, option.getStrike(), T);

    return currentSpot * std_normal_pdf(d1) * sqrt(T);
}

double BlackScholes::theta(double risklessRate, double currentSpot, const EuropeanOption& option) const
{
    const double T = static_cast<double>(option.maturity()) / _vol.period();

    const auto ds = d1_d2(risklessRate, currentSpot, option.getStrike(), T);
    const double d1 = ds.first;
    const double d2 = ds.second;

    const double firstTerm = (currentSpot * std_normal_cdf(d1) * _vol.value()) / (2. * sqrt(T));

    if (option.isCall()) {
        return -firstTerm - risklessRate * option.getStrike() * exp(-risklessRate * T) * std_normal_cdf(d2);
    }

    return -firstTerm + risklessRate * option.getStrike() * exp(-risklessRate * T) * std_normal_cdf(-d2);
}

double BlackScholes::rho(double risklessRate, double currentSpot, const EuropeanOption& option) const
{
    const double T = static_cast<double>(option.maturity()) / _vol.period();
    const double d2 = BlackScholes::d2(risklessRate, currentSpot, option.getStrike(), T);

    if (option.isCall()) {
        return option.getStrike() * T * exp(-risklessRate * T) * std_normal_cdf(d2);
    }

    return - option.getStrike() * T * exp(-risklessRate * T) * std_normal_cdf(-d2);
}

double BlackScholes::gamma(double risklessRate, double currentSpot, const EuropeanOption& option) const
{
    const double T = static_cast<double>(option.maturity()) / _vol.period();
    const double d1 = BlackScholes::d1(risklessRate, currentSpot, option.getStrike(), T);
    return  std_normal_pdf(d1)/ (currentSpot * _vol.value(option.maturity()));
}

double BlackScholes::d1(double r, double spot, double K, double T) const
{
    return (1. / (_vol.value() * sqrt(T)) * (log(spot / K) + (r + (pow(_vol.value(), 2) / 2)) * T));
}

double BlackScholes::d2(double r, double spot, double K, double T) const
{
    return d1_d2(r, spot, K, T).second;
}

std::pair<double, double> BlackScholes::d1_d2(double r, double spot, double K, double T) const
{
    const double volOnMaturity = _vol.value() * sqrt(T);
    const double d1 = (1. / volOnMaturity) * (log(spot / K) + (r + (pow(_vol.value(), 2) / 2)) * T);
    const double d2 = d1 - volOnMaturity;
    return { d1, d2 };
}
