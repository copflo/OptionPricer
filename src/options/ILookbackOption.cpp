#include "ILookbackOption.h"

ILookbackOption::ILookbackOption(Nature nature, int maturity, int obsFreq)
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