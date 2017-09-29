#ifndef BlackScholesMonteCarlo_h
#define BlackScholesMonteCarlo_h

#include <cmath>

#include "PathDependentOption.h"
#include "PathIndependentOption.h"
#include "MonteCarloSimulation.h"
#include "Volatility.h"


class BlackScholesMonteCarlo
{
public:
    template<typename... StopConditions>
    BlackScholesMonteCarlo(const Volatility& vol, StopSimulation* condition, StopConditions... conditions);
    BlackScholesMonteCarlo(const Volatility& vol, std::vector<StopSimulation*>& stopConditions);

    virtual ~BlackScholesMonteCarlo();

    double price(double risklessRate, double currentSpot, const PathIndependentOption& option) const;
    double price(double risklessRate, double currentSpot, const PathDependentOption& option)   const;
    void   print(std::ostream& os)                                                             const;

private:
    template <class Gen, class Opt> double runSimulation(Gen& generator, const Opt& option, double risklessRate, double currentSpot) const;

private:
    Volatility _vol;
    MonteCarloSimulation _simulation;
};

std::ostream& operator<<(std::ostream& os, const BlackScholesMonteCarlo& bs_montecarlo);


template<typename... StopConditions>
BlackScholesMonteCarlo::BlackScholesMonteCarlo(const Volatility& vol, StopSimulation* condition, StopConditions... conditions)
    : _vol(vol)
    , _simulation(condition, conditions...)
{
}

template <class Gen, class Opt>
double BlackScholesMonteCarlo::runSimulation(Gen& generator, const Opt& option, double risklessRate, double currentSpot) const
{
    auto payoff = [&generator, &option, currentSpot]() { return option.payoff(generator(currentSpot)); };
    const double T = static_cast<double>(option.maturity()) / _vol.period();
    return exp(-risklessRate * T) * _simulation.run(payoff).first;
}


#endif // BlackScholesMonteCarlo_h
