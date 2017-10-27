#include "ILookbackOption.h"

ILookbackOption::ILookbackOption(OptionNature* nature, int maturity, int obsFreq)
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
