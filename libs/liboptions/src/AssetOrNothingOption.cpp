#include "AssetOrNothingOption.h"


AssetOrNothingOption::AssetOrNothingOption(OptionNature* nature, size_t maturity, double strike)
    : DigitalOption(nature, maturity, strike)
{
}

AssetOrNothingOption::~AssetOrNothingOption()
{
}

double AssetOrNothingOption::payoff(double spot) const
{
    return successfulBet(spot)? spot : 0.0;
}

std::string AssetOrNothingOption::style() const
{
    return "Asset-or-nothing";
}
