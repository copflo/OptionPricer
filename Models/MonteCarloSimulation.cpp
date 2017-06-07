#include <algorithm>
#include <mutex>
#include <thread>

#include "MonteCarloSimulation.h"


struct MonteCarloSimulation::Runner
{
    Runner(const MonteCarloSimulation& simulation, RunningStats& statistics, std::function<double()>& random)
        : _simulation(simulation)
        , _statistics(statistics)
        , _random(random)
    {
    }

    void operator()()
    {
        while (_simulation.stop(_statistics) == false) {
            std::lock_guard<std::mutex> lock(_simulation._mutex);
            _statistics.update(_random());
        }
    }

    const MonteCarloSimulation& _simulation;
    RunningStats&          _statistics;
    std::function<double()>&    _random;
};

MonteCarloSimulation::MonteCarloSimulation(std::initializer_list<StopSimulation*>& stopConditions)
    : _stopConditions(stopConditions.begin(), stopConditions.end())
{
    if (_stopConditions.empty()) {
        throw std::runtime_error("No stop condition has been defined for the simulation");
    }
}

MonteCarloSimulation::MonteCarloSimulation(std::vector<StopSimulation*>& stopConditions)
    : _stopConditions(stopConditions.begin(), stopConditions.end())
{
    if (_stopConditions.empty()) {
        throw std::runtime_error("No stop condition has been defined for the simulation");
    }
}

MonteCarloSimulation::~MonteCarloSimulation()
{
}

std::pair<double, double> MonteCarloSimulation::run(std::function<double(void)> random) const
{
    RunningStats simulation;
    //for (; stop(simulation) == false; simulation.update(random()));

    std::thread threads[7];
    for (auto& thread : threads) {
        thread = std::thread(Runner(*this, simulation, random));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return std::pair<double, double>(simulation.mean(), simulation.stdDeviation());
}

void MonteCarloSimulation::print(std::ostream& os) const
{
    os << "Monte Carlo simulation";
}

bool MonteCarloSimulation::stop(const RunningStats& simulation) const
{
    return std::any_of(_stopConditions.begin(), _stopConditions.end(), 
        [&simulation](const auto& condition) { return condition->stop(simulation); });
}

std::ostream& operator<<(std::ostream& os, const MonteCarloSimulation& montecarlo)
{
    montecarlo.print(os);
    return os;
}