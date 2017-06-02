#ifndef SpotRandomVariable_h
#define SpotRandomVariable_h

#include "GaussianRandomVariable.h"
#include "Volatility.h"

class BlackScholesSpot
{
public:
    BlackScholesSpot (double riskfreeRate, int period, const Volatility& vol);
    ~BlackScholesSpot();

    double            riskfreeRate()                const;
    int               period      ()                const;
    const Volatility& volatility  ()                const;
    double            operator()  (double initSpot);

private:
    double     _riskfreeRate;
    int        _period;
    Volatility _vol;
    GaussianRV _brownian;
};

#endif /* SpotRandomVariable_h */