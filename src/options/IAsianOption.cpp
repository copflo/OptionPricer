#include "IAsianOption.h"

IAsianOption::IAsianOption(OptionNature* nature, int maturity, int obsFreq)
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
