#include "AssetOrNothingOption.h"

AssetOrNothingOption::AssetOrNothingOption(Option::Nature nature, int maturity, double strike)
    : DigitalOption(nature, maturity, strike)
{
}

AssetOrNothingOption::~AssetOrNothingOption()
{
}

std::string AssetOrNothingOption::style() const
{
    return "Asset-or-nothing";
}

double AssetOrNothingOption::payoff(double spot) const
{
    return successfulBet(spot)? spot : 0.0;
}
