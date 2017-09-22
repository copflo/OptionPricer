#include "FixedStrike.h"

FixedStrike::FixedStrike(double strike)
    : _strike(strike)
{
}

FixedStrike::~FixedStrike()
{
}

double FixedStrike::getStrike() const
{
    return _strike;
}
