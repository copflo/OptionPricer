#include "FixedStrike.h"

FixedStrike::FixedStrike(double strike)
    : _strike(strike)
{
}

FixedStrike::~FixedStrike()
{
}

double FixedStrike::strike() const
{
    return _strike;
}
