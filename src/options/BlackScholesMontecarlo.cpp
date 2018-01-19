#include "BlackScholesMontecarlo.h"
#include "PathGenerator.h"
#include "BlackScholesSpot.h"


BlackScholesMonteCarlo::BlackScholesMonteCarlo(const Volatility& vol, std::vector<StopSimulation*>& stopConditions)
    : _vol(vol)
    , _simulation(stopConditions)
{
}

BlackScholesMonteCarlo::~BlackScholesMonteCarlo()
{
}

double BlackScholesMonteCarlo::price(double risklessRate, double currentSpot, const PathIndependentOption& option) const
{
    BlackScholesSpot spot(risklessRate, option.maturity(), _vol);
    return runSimulation(spot, option, risklessRate, currentSpot);
}

double BlackScholesMonteCarlo::price(double risklessRate, double currentSpot, const PathDependentOption& option) const
{
    const int observationPeriod = option.observationFrequency();
    const size_t nbObs = option.maturity() / observationPeriod;
    SpotPathGenerator path(risklessRate, _vol, nbObs, observationPeriod);
    return runSimulation(path, option, risklessRate, currentSpot);
}

void BlackScholesMonteCarlo::print(std::ostream& os) const
{
    os << _simulation << " of Black Scholes model";
}

std::ostream& operator<<(std::ostream& os, const BlackScholesMonteCarlo& bs_montecarlo)
{
    bs_montecarlo.print(os);
    return os;
}
