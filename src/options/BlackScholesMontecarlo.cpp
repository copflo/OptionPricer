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

std::tuple<double, double, double> BlackScholesMonteCarlo::hedge(double r, double s0, const PathIndependentOption& option) const
{
	throw std::runtime_error("Not implemented");
}

double BlackScholesMonteCarlo::price(double r, double s0, const PathIndependentOption& option) const
{
    BlackScholesSpot spot(r, option.maturity(), _vol);
    return runSimulation(spot, option, r, s0);
}

double BlackScholesMonteCarlo::price(double r, double s0, const PathDependentOption& option) const
{
    const int observationPeriod = option.observationFrequency();
    const size_t nbObs = option.maturity() / observationPeriod;
    SpotPathGenerator path(r, _vol, nbObs, observationPeriod);
    return runSimulation(path, option, r, s0);
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
