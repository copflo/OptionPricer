#include <algorithm>
#include "FloatingStrikeLookbackOption.h"

FloatingStrikeLookbackOption::FloatingStrikeLookbackOption(Nature nature, int maturity, int obsFreq)
    : LookbackOption(nature, maturity, obsFreq)
{
}

FloatingStrikeLookbackOption::~FloatingStrikeLookbackOption()
{
}

double FloatingStrikeLookbackOption::payoff(const std::vector<double>& spot_path) const
{
    return Option::payoff(spot_path.back(), strike(spot_path));
}

double FloatingStrikeLookbackOption::strike(const std::vector<double>& spot_path) const
{
    if (isCall()) {
        return *std::min_element(spot_path.begin(), spot_path.end());
    }

    return *std::max_element(spot_path.begin(), spot_path.end());
}

void FloatingStrikeLookbackOption::print(std::ostream& os) const
{
    LookbackOption::print(os);
    os << "Strike: floating" << std::endl;
}
