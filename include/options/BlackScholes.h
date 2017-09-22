#ifndef BlackSholes_h
#define BlackSholes_h

#include "AmericanOption.h"
#include "AssetOrNothingOption.h"
#include "CashOrNothingOption.h"
#include "EuropeanOption.h"

#include "OptionSensitivity.h"
#include "Volatility.h"


class BlackScholes
{
public:
    BlackScholes (const Volatility& vol);
    ~BlackScholes();

    double price(double risklessRate, double currentSpot, const EuropeanOption& option)       const;
    double price(double risklessRate, double currentSpot, const CashOrNothingOption& option)  const;
    double price(double risklessRate, double currentSpot, const AssetOrNothingOption& option) const;

    template<class OptionStyle>
    OptionSensitivity sensitivity(double risklessRate, double currentSpot, const OptionStyle& option) const
    {
        return OptionSensitivity(delta(risklessRate, currentSpot, option),
                                 vega(risklessRate, currentSpot, option),
                                 theta(risklessRate, currentSpot, option),
                                 rho(risklessRate, currentSpot, option),
                                 gamma(risklessRate, currentSpot, option));
    }

    double delta(double risklessRate, double currentSpot, const EuropeanOption& option) const;

    double vega(double risklessRate, double currentSpot, const EuropeanOption& option) const;

    double theta(double risklessRate, double currentSpot, const EuropeanOption& option) const;

    double rho(double risklessRate, double currentSpot, const EuropeanOption& option) const;

    double gamma(double risklessRate, double currentSpot, const EuropeanOption& option) const;

private:
    Volatility _vol;

private:
    double                    d1   (double r, double spot, double K, double T) const;
    double                    d2   (double r, double spot, double K, double T) const;
    std::pair<double, double> d1_d2(double r, double spot, double K, double T) const;
};


#endif // BlackSholes_h
