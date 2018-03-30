#include "IAsianOption.h"

IAsianOption::IAsianOption(OptionNature* nature, size_t maturity, size_t obsFreq)
    : PathDependentOption(nature, maturity, obsFreq)
{
}

IAsianOption::~IAsianOption()
{
}

std::string IAsianOption::style() const
{
    return "Asian";
}
