#ifndef BS_StockPriceGen_h
#define BS_StockPriceGen_h

#include "BlackScholesGen.h"
#include "GaussianRandomVariable.h"
#include "Volatility.h"


class BS_StockPriceGen
    : public BlackScholesGen
{
public:
    BS_StockPriceGen (double riskfreeRate, size_t period, const Volatility& vol);
    ~BS_StockPriceGen();

    double operator()(double s0);

private:
    double     _T;
    GaussianRV _Z;
};


#endif // BS_StockPriceGen_h
