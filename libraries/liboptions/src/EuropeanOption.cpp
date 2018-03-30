#include "EuropeanOption.h"


EuropeanOption::EuropeanOption(OptionNature* nature, size_t maturity, double strike)
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
