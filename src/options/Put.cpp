#include <cmath>

#include "Put.h"


bool Put::isCall() const
{
    return false;
}

bool Put::isPut() const
{
    return true;
}

double Put::payoff(double spot, double strike) const
{
    return fmax(strike - spot, 0.0);
}

std::string Put::toString() const
{
    return "put";
}
