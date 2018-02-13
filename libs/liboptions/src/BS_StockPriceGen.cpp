#include "BS_StockPriceGen.h"


BS_StockPriceGen::BS_StockPriceGen(double riskfreeRate, size_t period, const Volatility & vol)
	: BlackScholesGen(riskfreeRate, vol)
	, _T(static_cast<double>(period) / vol.period())
	, _Z(0.0, sqrt(_T))
{
}

BS_StockPriceGen::~BS_StockPriceGen()
{
}

double BS_StockPriceGen::operator()(double initSpot)
{
    return spot(initSpot, _T, _Z());
}
