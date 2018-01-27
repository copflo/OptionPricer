#ifndef BlackScholesMonteCarlo_h
#define BlackScholesMonteCarlo_h

#include <cmath>
#include <tuple>

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

	/* Returns the price of the option with the delta and the gamma for a path independent option
	 * @param r the riskless rate
	 * @param s0 the initial spot
	 * @param option the option to price
	 * @return the price, the delta, the gamma
	 */
	std::tuple<double, double, double> hedge(double r, double s0, const PathIndependentOption& option) const;

    double price(double r, double s0, const PathIndependentOption& option) const;
    double price(double r, double s0, const PathDependentOption& option)   const;
    void   print(std::ostream& os)                                         const;

private:
    template <class Gen, class Opt>
    double runSimulation(Gen& gen, const Opt& option, double r, double s0) const;

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
double BlackScholesMonteCarlo::runSimulation(Gen& gen, const Opt& option, double r, double s0) const
{
    auto payoff = [&gen, &option, s0]() { return option.payoff(gen(s0)); };
    const double T = static_cast<double>(option.maturity()) / _vol.period();
    return exp(-r * T) * _simulation.run(payoff).mean();
}


#endif // BlackScholesMonteCarlo_h
