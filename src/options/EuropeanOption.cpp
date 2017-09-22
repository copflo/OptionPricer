#include "EuropeanOption.h"

EuropeanOption::EuropeanOption(Nature nature, int maturity, double strike)
    : VanillaOption(nature, maturity, strike)
{
}

EuropeanOption::~EuropeanOption()
{
}

std::string EuropeanOption::style() const
{
    return "European";
}
