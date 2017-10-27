#include "AmericanOption.h"

AmericanOption::AmericanOption(OptionNature* nature, int maturity, double strike)
    : VanillaOption(nature, maturity, strike)
{
}

AmericanOption::~AmericanOption()
{
}

std::string AmericanOption::style() const
{
    return "American";
}
