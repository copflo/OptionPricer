#include "LookbackOption.h"

LookbackOption::LookbackOption(Nature nature, int maturity, int obsFreq)
    : PathDependentOption(nature, maturity, obsFreq)
{
}

LookbackOption::~LookbackOption()
{
}

std::string LookbackOption::style() const
{
    return "Lookback";
}