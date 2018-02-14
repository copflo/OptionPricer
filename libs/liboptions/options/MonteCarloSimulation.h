#ifndef MonteCarlo_h
#define MonteCarlo_h

#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <vector>

#include "AccuracyConfidence.h"
#include "NbObs.h"
#include "TimeLimit.h"


class MonteCarloSimulation
{
private:
  static double randomValue(std::function<double()> random, std::mutex& randMtx);

public:
    template<typename... StopConditions>
    MonteCarloSimulation (StopSimulation* condition, StopConditions... conditions);
    MonteCarloSimulation (std::vector<StopSimulation*>& stopConditions);
    ~MonteCarloSimulation();

    RunningStats run  (std::function<double()> random) const;
    void         print(std::ostream& os)               const;

private:
    MonteCarloSimulation(std::initializer_list<StopSimulation*> stopConditions);

    void runSimulation(RunningStats& stats, std::function<double()> random, std::mutex& statsMtx, std::mutex& randMtx) const;
    bool updateStats  (RunningStats& stats, double value, std::mutex& statsMtx)                                        const;
    bool stop         (const RunningStats& stats)                                                                      const;

private:
     std::vector<std::unique_ptr<StopSimulation>> _stopConditions;
};

std::ostream& operator<<(std::ostream& os, const MonteCarloSimulation& montecarlo);


template<typename... StopConditions>
MonteCarloSimulation::MonteCarloSimulation(StopSimulation* condition, StopConditions... conditions)
    : MonteCarloSimulation{ condition, conditions... }
{
}


#endif // MonteCarlo_h