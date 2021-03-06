#include "DigitalOption.h"

DigitalOption::DigitalOption(OptionNature* nature, size_t maturity, double strike)
    : PathIndependentOption(nature, maturity, strike)
{
}

DigitalOption::~DigitalOption()
{
}

bool DigitalOption::successfulBet(double spot) const
{
    if (isCall()) {
        return spot >= _strike;
    }

    return spot <= _strike;
}
