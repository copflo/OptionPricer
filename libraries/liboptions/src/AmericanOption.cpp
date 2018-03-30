#include "AmericanOption.h"

AmericanOption::AmericanOption(OptionNature* nature, size_t maturity, double strike)
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
