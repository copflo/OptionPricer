#include "BlackScholesSpot.h"


BlackScholesSpot::BlackScholesSpot(double riskfreeRate, size_t period, const Volatility & vol)
	: BlackScholesGen(riskfreeRate, vol)
	, _T(static_cast<double>(period) / vol.period())
	, _Z(0.0, sqrt(_T))
{
}

BlackScholesSpot::~BlackScholesSpot()
{
}

double BlackScholesSpot::operator()(double initSpot)
{
    return spot(initSpot, _T, _Z());
}
