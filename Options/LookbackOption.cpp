#include <algorithm>

#include "LookbackOption.h"


LookbackOption<FixedStrike>::LookbackOption(Option::Nature nature, int maturity, int obsFreq, double strike)
    : ILookbackOption(nature, maturity, obsFreq)
    , FixedStrike(strike)
{
}

LookbackOption<FixedStrike>::~LookbackOption()
{
}

double LookbackOption<FixedStrike>::payoff(const std::vector<double>& spot_path) const
{
    return Option::payoff(optimalSpot(spot_path), _strike);
}

void LookbackOption<FixedStrike>::print(std::ostream& os) const
{
    ILookbackOption::print(os);
    os << "Strike: " << _strike << std::endl;
}

double LookbackOption<FixedStrike>::optimalSpot(const std::vector<double>& spot_path) const
{
    if (isCall()) {
        return *std::max_element(spot_path.begin(), spot_path.end());
    }
    else {
        return *std::min_element(spot_path.begin(), spot_path.end());
    }
}


LookbackOption<FloatingStrike>::LookbackOption(Nature nature, int maturity, int obsFreq)
    : ILookbackOption(nature, maturity, obsFreq)
{
}

LookbackOption<FloatingStrike>::~LookbackOption()
{
}

double LookbackOption<FloatingStrike>::payoff(const std::vector<double>& spot_path) const
{
    return Option::payoff(spot_path.back(), strike(spot_path));
}

double LookbackOption<FloatingStrike>::strike(const std::vector<double>& spot_path) const
{
    if (isCall()) {
        return *std::min_element(spot_path.begin(), spot_path.end());
    }

    return *std::max_element(spot_path.begin(), spot_path.end());
}

void LookbackOption<FloatingStrike>::print(std::ostream& os) const
{
    ILookbackOption::print(os);
    os << "Strike: floating" << std::endl;
}