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

double BlackScholes::price(double r, double spot, const EuropeanOption& option) const
{
    const double T = static_cast<double>(option.maturity()) / _vol.period();
    const auto ds = d1_d2(r, spot, option.strike(), T);
    const double d1 = ds.first;
    const double d2 = ds.second;

    if (option.isCall()) {
        return (spot * std_normal_cdf(d1)) - (option.strike() * exp(-r * T) * std_normal_cdf(d2));
    }
    return (option.strike() * exp(-r * T) * std_normal_cdf(-d2)) - (spot * std_normal_cdf(-d1));
}

double BlackScholes::price(double r, double s0, const CashOrNothingOption& option) const
{
    const double T = static_cast<double>(option.maturity()) / _vol.period();
    const auto d2 = BlackScholes::d2(r, s0, option.strike(), T);

    if (option.isCall()) {
        return exp(-r * T) * std_normal_cdf(d2) * option.rebate();
    }
    return exp(-r * T) * std_normal_cdf(-d2) * option.rebate();
}

double BlackScholes::price(double r, double s0, const AssetOrNothingOption& option) const
{
    const double T = static_cast<double>(option.maturity()) / _vol.period();
    const double d1 = BlackScholes::d1(r, s0, option.strike(), T);

    if (option.isCall()) {
        return s0 * std_normal_cdf(d1);
    }
    return s0 * std_normal_cdf(-d1);;
}

double BlackScholes::delta(double r, double s0, const EuropeanOption& option) const
{
    const double T = static_cast<double>(option.maturity()) / _vol.period();
    const double d1 = BlackScholes::d1(r, s0, option.strike(), T);

    if (option.isCall()) {
        return std_normal_cdf(d1);
    }
    return std_normal_cdf(d1) - 1.;
}

double BlackScholes::vega(double r, double s0, const EuropeanOption& option) const
{
    const double T = static_cast<double>(option.maturity()) / _vol.period();
    const double d1 = BlackScholes::d1(r, s0, option.strike(), T);

    return s0 * std_normal_pdf(d1) * sqrt(T);
}

double BlackScholes::theta(double r, double s0, const EuropeanOption& option) const
{
    const double T = static_cast<double>(option.maturity()) / _vol.period();

    const auto ds = d1_d2(r, s0, option.strike(), T);
    const double d1 = ds.first;
    const double d2 = ds.second;

    const double firstTerm = (s0 * std_normal_cdf(d1) * _vol.value()) / (2. * sqrt(T));

    if (option.isCall()) {
        return -firstTerm - r * option.strike() * exp(-r * T) * std_normal_cdf(d2);
    }
    return -firstTerm + r * option.strike() * exp(-r * T) * std_normal_cdf(-d2);
}

double BlackScholes::rho(double r, double s0, const EuropeanOption& option) const
{
    const double T = static_cast<double>(option.maturity()) / _vol.period();
    const double d2 = BlackScholes::d2(r, s0, option.strike(), T);

    if (option.isCall()) {
        return option.strike() * T * exp(-r * T) * std_normal_cdf(d2);
    }
    return - option.strike() * T * exp(-r * T) * std_normal_cdf(-d2);
}

double BlackScholes::gamma(double r, double s0, const EuropeanOption& option) const
{
    const double T = static_cast<double>(option.maturity()) / _vol.period();
    const double d1 = BlackScholes::d1(r, s0, option.strike(), T);
    return  std_normal_pdf(d1)/ (s0 * _vol.value(option.maturity()));
}

double BlackScholes::d1(double r, double spot, double K, double T) const
{
    const double sigma = _vol.value();
    return (1. / (_vol.value() * sqrt(T)) * (log(spot / K) + (r + sigma * sigma / 2) * T));
}

double BlackScholes::d2(double r, double spot, double K, double T) const
{
    return d1_d2(r, spot, K, T).second;
}

std::pair<double, double> BlackScholes::d1_d2(double r, double spot, double K, double T) const
{
    const double sigma = _vol.value();
    const double volOnMaturity = sigma * sqrt(T);
    const double d1 = (1. / volOnMaturity) * (log(spot / K) + (r + sigma * sigma / 2) * T);
    const double d2 = d1 - volOnMaturity;
    return { d1, d2 };
}
