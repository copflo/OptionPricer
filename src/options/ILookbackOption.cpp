#include "ILookbackOption.h"

ILookbackOption::ILookbackOption(OptionNature* nature, size_t maturity, size_t obsFreq)
    : PathDependentOption(nature, maturity, obsFreq)
{
}

ILookbackOption::~ILookbackOption()
{
}

std::string ILookbackOption::style() const
{
    return "Lookback";
}
