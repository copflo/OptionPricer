#include "VanillaOption.h"

VanillaOption::VanillaOption(Nature nature, int maturity, double strike)
    : PathIndependentOption(nature, maturity, strike)
{
}

VanillaOption::~VanillaOption()
{
}

double VanillaOption::payoff(double spot) const
{
    return Option::payoff(spot, _strike);
}
