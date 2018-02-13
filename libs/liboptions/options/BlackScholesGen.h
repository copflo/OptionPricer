#ifndef BLACKSCHOLESGEN_H
#define BLACKSCHOLESGEN_H

#include "Volatility.h"


class BlackScholesGen
{
public:
    virtual ~BlackScholesGen();

protected:
    BlackScholesGen(double r, const Volatility& vol);
    double spot(double s0, double T, double brown);

protected:
    double     _riskfreeRate;
    Volatility _vol;
};


#endif // BLACKSCHOLESGEN_H
