#include <algorithm>
#include "FixedStrikeLookbackOption.h"

FixedStrikeLookbackOption::FixedStrikeLookbackOption(Nature nature, int maturity, int obsFreq, double strike)
    : LookbackOption(nature, maturity, obsFreq)
    , FixedStrike(strike)
{
}

FixedStrikeLookbackOption::~FixedStrikeLookbackOption()
{
}

double FixedStrikeLookbackOption::payoff(const std::vector<double>& spot_path) const
{
    return Option::payoff(optimalSpot(spot_path), _strike);
}

void FixedStrikeLookbackOption::print(std::ostream& os) const
{
    LookbackOption::print(os);
    os << "Strike: " << _strike << std::endl;
}

double FixedStrikeLookbackOption::optimalSpot(const std::vector<double>& spot_path) const
{
    if (isCall()) {
        return *std::max_element(spot_path.begin(), spot_path.end());
    }
    else {
        return *std::min_element(spot_path.begin(), spot_path.end());
    }
}
