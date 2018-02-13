#ifndef SpotRandomVariable_h
#define SpotRandomVariable_h

#include "BlackScholesGen.h"
#include "GaussianRandomVariable.h"
#include "Volatility.h"


class BlackScholesSpot
    : public BlackScholesGen
{
public:
    BlackScholesSpot (double riskfreeRate, size_t period, const Volatility& vol);
    ~BlackScholesSpot();

    double operator()(double s0);

private:
    double     _T;
    GaussianRV _Z;
};


#endif // SpotRandomVariable_h
