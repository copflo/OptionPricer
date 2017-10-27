#include "VanillaOption.h"

VanillaOption::VanillaOption(OptionNature* nature, int maturity, double strike)
    : PathIndependentOption(nature, maturity, strike)
{
}

VanillaOption::~VanillaOption()
{
}

double VanillaOption::payoff(double spot) const
{
    return _nature->payoff(spot, _strike);
}
