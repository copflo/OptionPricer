#ifndef SpotSimulator_h
#define SpotSimulator_h

#include "NormalDistributionSimulator.h"
#include "Volatility.h"

class SpotSimulator
{
public:
    SpotSimulator();
    ~SpotSimulator();

    double simulate(double risklessRate, double spot0, const Volatility& vol, const Period& period);

private:
    NormalDistributionSimulator _brownian;
};

#endif /* SpotSimulator_h */