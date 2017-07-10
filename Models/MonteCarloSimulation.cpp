#include <algorithm>
#include <thread>

#include "MonteCarloSimulation.h"


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
    std::mutex mutex;

    const size_t nbThreads = 8;
    std::vector<std::thread> threads;
    threads.reserve(nbThreads);
    auto task = std::bind(&MonteCarloSimulation::runSimulation, this, std::ref(stats), random, std::ref(mutex));
    
    for (int count = 0; count < nbThreads; ++count) {
        threads.emplace_back(task);
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

void MonteCarloSimulation::runSimulation(RunningStats& stats, std::function<double()> random, std::mutex& mtx) const
{
    bool keepRunning = true;
    do {
        std::lock_guard<std::mutex> lock(mtx);
        if ((keepRunning = !stop(stats))) {
            stats.update(random());
        }
    } while(keepRunning);
}

bool MonteCarloSimulation::stop(const RunningStats& stats) const
{
    return std::any_of(_stopConditions.begin(), _stopConditions.end(),
        [&stats](const auto& condition) { return condition->stop(stats); });
}

std::ostream& operator<<(std::ostream& os, const MonteCarloSimulation& montecarlo)
{
    montecarlo.print(os);
    return os;
}