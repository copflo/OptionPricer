#include <algorithm>
#include <thread>

#include "SimulationRunner.h"


double SimulationRunner::randomValue(std::function<double()> random, std::mutex& randMtx)
{
    std::lock_guard<std::mutex> lock(randMtx);
    return random();
}


SimulationRunner::SimulationRunner(std::vector<StopSimulation*>& stopConditions)
    : _stopConditions(stopConditions.begin(), stopConditions.end())
{
    if (_stopConditions.empty()) {
        throw std::runtime_error("No stop condition has been defined for the simulation");
    }
}

SimulationRunner::~SimulationRunner()
{
}

MC_Simulation SimulationRunner::run(std::function<double()> random) const
{
    MC_Simulation stats;
    std::mutex statsMtx, randMtx;

    const size_t nbThreads = 2;
    std::vector<std::thread> threads;
    threads.reserve(nbThreads);
    auto task = std::bind(&SimulationRunner::runSimulation,
                          this,
                          std::ref(stats),
                          random,
                          std::ref(statsMtx),
                          std::ref(randMtx));

    for (size_t count = 0; count < nbThreads; ++count) {
        threads.emplace_back(task);
    }
    for (auto& thread : threads) {
        thread.join();
    }
    return stats;
}

void SimulationRunner::print(std::ostream& os) const
{
    os << "Monte Carlo simulation";
}

SimulationRunner::SimulationRunner(std::initializer_list<StopSimulation*> stopConditions)
    : _stopConditions(stopConditions.begin(), stopConditions.end())
{
}

void SimulationRunner::runSimulation(MC_Simulation& sim,
                                     std::function<double()> random,
                                     std::mutex& simMtx,
                                     std::mutex& randMtx) const
{
    while(updateStats(sim, randomValue(random, randMtx), simMtx));
}

bool SimulationRunner::updateStats(MC_Simulation& sim,
                                   double value,
                                   std::mutex& simMtx) const
{
    std::lock_guard<std::mutex> lock(simMtx);
    if(!stop(sim)) {
        sim.update(value);
        return true;
    }
    return false;
}

bool SimulationRunner::stop(const MC_Simulation& sim) const
{
    return std::any_of(_stopConditions.begin(), _stopConditions.end(),
                [&sim](const std::unique_ptr<StopSimulation>& condition) {
		              return condition->stop(sim);
                });
}

std::ostream& operator<<(std::ostream& os, const SimulationRunner& simRunner)
{
    simRunner.print(os);
    return os;
}
