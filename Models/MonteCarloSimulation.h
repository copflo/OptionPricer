#ifndef MonteCarlo_h
#define MonteCarlo_h

#include <functional>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <mutex>
#include <vector>

#include "StopSimulation.h"

class MonteCarloSimulation
{
public:
    template<typename... StopConditions>
    MonteCarloSimulation (StopSimulation* condition, StopConditions... conditions);
    MonteCarloSimulation (std::initializer_list<StopSimulation*>& stopConditions);
    MonteCarloSimulation (std::vector<StopSimulation*>& stopConditions);
    ~MonteCarloSimulation();

    std::pair<double, double> run  (std::function<double(void)> random) const;
    void                      print(std::ostream& os)                   const;

private:
    bool stop(const RunningSimulation& simulation) const;

private:
    mutable std::mutex                                   _mutex;
            std::vector<std::unique_ptr<StopSimulation>> _stopConditions;

private:
    struct Runner;
};

template<typename... StopConditions>
MonteCarloSimulation::MonteCarloSimulation(StopSimulation* condition, StopConditions... conditions)
    : MonteCarloSimulation(std::initializer_list<StopSimulation*>{ condition, conditions... })
{
}

std::ostream& operator<<(std::ostream& os, const MonteCarloSimulation& montecarlo);

#endif /* MonteCarlo_h */