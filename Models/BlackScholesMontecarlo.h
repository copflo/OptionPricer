#ifndef BlackScholesMonteCarlo_h
#define BlackScholesMonteCarlo_h

#include "MonteCarloSimulation.h"
#include "../Options/PathDependentOption.h"
#include "../Options/PathIndependentOption.h"
#include "Volatility.h"

class BlackScholesMonteCarlo
{
public:
    template<typename... StopConditions>
    BlackScholesMonteCarlo(const Volatility& vol, 
                           StopSimulation*   condition, 
                           StopConditions... conditions);

    BlackScholesMonteCarlo(const Volatility& vol, 
                           std::initializer_list<StopSimulation*>& stopConditions);

    BlackScholesMonteCarlo(const Volatility& vol,
                           std::vector<StopSimulation*>& stopConditions);

    BlackScholesMonteCarlo(const Volatility& vol,
                           std::vector<StopSimulation*>&& stopConditions);

    virtual ~BlackScholesMonteCarlo();

    double price(double risklessRate, double currentSpot, const PathIndependentOption& option) const;
    double price(double risklessRate, double currentSpot, const PathDependentOption& option)   const;
    void   print(std::ostream& os)                                                             const;

private:
    Volatility _vol;
    MonteCarloSimulation _simulation;
};

template<typename... StopConditions>
BlackScholesMonteCarlo::BlackScholesMonteCarlo(const Volatility& vol,
                                               StopSimulation*   condition,
                                               StopConditions... conditions)
    : _vol(vol)
    , _simulation(condition, conditions...)
{
}

std::ostream& operator<<(std::ostream& os, const BlackScholesMonteCarlo& bs_montecarlo);

#endif /* BlackScholesMonteCarlo_h */