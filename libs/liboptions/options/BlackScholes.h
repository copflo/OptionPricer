#ifndef BlackSholes_h
#define BlackSholes_h

#include "AmericanOption.h"
#include "AssetOrNothingOption.h"
#include "CashOrNothingOption.h"
#include "EuropeanOption.h"

#include "greeks.h"
#include "Volatility.h"


class BlackScholes
{
public:
    BlackScholes (const Volatility& vol);
    ~BlackScholes();

    double price(double r, double s0, const EuropeanOption& option)       const;
    double price(double r, double s0, const CashOrNothingOption& option)  const;
    double price(double r, double s0, const AssetOrNothingOption& option) const;

    template<class Opt>
    Greeks greeks(double r, double s0, const Opt& option) const;
    double delta (double r, double s0, const EuropeanOption& option) const;
    double vega  (double r, double s0, const EuropeanOption& option) const;
    double theta (double r, double s0, const EuropeanOption& option) const;
    double rho   (double r, double s0, const EuropeanOption& option) const;
    double gamma (double r, double s0, const EuropeanOption& option) const;

private:
    Volatility _vol;

private:
    double                    d1   (double r, double spot, double K, double T) const;
    double                    d2   (double r, double spot, double K, double T) const;
    std::pair<double, double> d1_d2(double r, double spot, double K, double T) const;
};


template<class Opt>
Greeks BlackScholes::greeks(double r, double s0, const Opt& option) const
{
    return Greeks(delta(r, s0, option),
                  vega(r, s0, option),
                  theta(r, s0, option),
                  rho(r, s0, option),
                  gamma(r, s0, option));
}


#endif // BlackSholes_h
