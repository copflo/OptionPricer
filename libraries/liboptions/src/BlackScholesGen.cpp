#include <cmath>

#include "BlackScholesGen.h"


BlackScholesGen::~BlackScholesGen()
{
}

BlackScholesGen::BlackScholesGen(double r, const Volatility& vol)
        : _riskfreeRate(r)
        , _vol(vol)
{
}

double BlackScholesGen::spot(double s0, double t, double Bt)
{
    const double drift = _riskfreeRate - _vol.value() * _vol.value() / 2.;
    return s0 * exp(drift * t + _vol.value() * Bt);
}
