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
    auto payoff = [&spot, &option, currentSpot]() { return option.payoff(spot(currentSpot)); };

    const double T = static_cast<double>(option.maturity()) / _vol.period();
    return exp(-risklessRate * T) * _simulation.run(payoff).first;
}

double BlackScholesMonteCarlo::price(double risklessRate, double currentSpot, const PathDependentOption& option) const
{
    const int observationPeriod = option.observationFrequency();
    const size_t nbObs = option.maturity() / observationPeriod;
    
    SpotPathGenerator path(nbObs, risklessRate, _vol, observationPeriod);
    auto payoff = [&path, &option, currentSpot]() { return option.payoff(path(currentSpot)); };

    const double T = static_cast<double>(option.maturity()) / _vol.period();
    return exp(-risklessRate * T) * _simulation.run(payoff).first;
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