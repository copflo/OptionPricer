#include <algorithm>
#include <thread>

#include "MonteCarloSimulation.h"


double MonteCarloSimulation::randomValue(std::function<double()> random, std::mutex& randMtx)
{
    std::lock_guard<std::mutex> lock(randMtx);
    return random();
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

RunningStats MonteCarloSimulation::run(std::function<double()> random) const
{
    RunningStats stats;
    std::mutex statsMtx, randMtx;

    const size_t nbThreads = 8;
    std::vector<std::thread> threads;
    threads.reserve(nbThreads);
    auto task = std::bind(&MonteCarloSimulation::runSimulation, this, std::ref(stats), random, std::ref(statsMtx), std::ref(randMtx));

    for (size_t count = 0; count < nbThreads; ++count) {
        threads.emplace_back(task);
    }
    for (auto& thread : threads) {
        thread.join();
    }
    return stats;
}

void MonteCarloSimulation::print(std::ostream& os) const
{
    os << "Monte Carlo simulation";
}

MonteCarloSimulation::MonteCarloSimulation(std::initializer_list<StopSimulation*> stopConditions)
    : _stopConditions(stopConditions.begin(), stopConditions.end())
{
}

void MonteCarloSimulation::runSimulation(RunningStats& stats, std::function<double()> random, std::mutex& statsMtx, std::mutex& randMtx) const
{
    while(updateStats(stats, randomValue(random, randMtx), statsMtx));
}

bool MonteCarloSimulation::updateStats(RunningStats& stats, double value, std::mutex& statsMtx) const
{
    std::lock_guard<std::mutex> lock(statsMtx);
    if(!stop(stats)) {
        stats.update(value);
        return true;
    }
    return false;
}

bool MonteCarloSimulation::stop(const RunningStats& stats) const
{
    return std::any_of(_stopConditions.begin(), _stopConditions.end(), [&stats](const std::unique_ptr<StopSimulation>& condition) {
		    return condition->stop(stats);
    });
}

std::ostream& operator<<(std::ostream& os, const MonteCarloSimulation& montecarlo)
{
    montecarlo.print(os);
    return os;
}
