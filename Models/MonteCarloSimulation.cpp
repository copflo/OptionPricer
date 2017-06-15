#include <algorithm>
#include <mutex>
#include <thread>

#include "MonteCarloSimulation.h"

typedef std::vector<std::unique_ptr<StopSimulation>> StopConditions;
struct Runner
{
    Runner(const StopConditions&   stopConditions, 
           RunningStats&           statistics, 
           std::function<double()> random,
           std::mutex&             mutex)
        : _stopConditions(stopConditions)
        , _statistics(statistics)
        , _random(random)
        , _mutex(mutex)
    {
    }

    void operator()()
    {
        while (!stop()) {
            _statistics.update(_random());
            _mutex.unlock();
        }
        _mutex.unlock();
    }

    bool stop() const
    {
        _mutex.lock();
        return std::any_of(_stopConditions.begin(), _stopConditions.end(), 
            [this](const auto& condition) { return condition->stop(_statistics); });
    }

    const StopConditions&   _stopConditions;
    RunningStats&           _statistics;
    std::function<double()> _random;
    std::mutex&             _mutex;
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

std::pair<double, double> MonteCarloSimulation::run(std::function<double()> random) const
{
    RunningStats stats;
    std::thread threads[7];
    std::mutex mutex;

    for (auto& thread : threads) {
        thread = std::thread(Runner(_stopConditions, stats, random, mutex));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return std::pair<double, double>(stats.mean(), stats.stdDeviation());
}

void MonteCarloSimulation::print(std::ostream& os) const
{
    os << "Monte Carlo simulation";
}

std::ostream& operator<<(std::ostream& os, const MonteCarloSimulation& montecarlo)
{
    montecarlo.print(os);
    return os;
}