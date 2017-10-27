#include <cmath>

#include "Call.h"


bool Call::isCall() const
{
    return true;
}

bool Call::isPut() const
{
    return false;
}

double Call::payoff(double spot, double strike) const
{
    return fmax(spot - strike, 0.0);
}

std::string Call::toString() const
{
    return "call";
}
