#include <cmath>

#include "MC_Simulation.h"


MC_Simulation::MC_Simulation()
    : _nbIter(0)
    , _mean(0.0)
    , _squareSumOfDiff(0.0)
    , _begin(std::chrono::system_clock::now())
{
}

MC_Simulation::~MC_Simulation()
{
}

void MC_Simulation::update(double value)
{
    const double bufferMean = _mean;
    _mean = _mean + (value - _mean) / (++_nbIter);
    if (_nbIter > 1) {
        _squareSumOfDiff += (value - bufferMean) * (value - _mean);
    }
}

double MC_Simulation::mean() const
{
    return _mean;
}

double MC_Simulation::variance() const
{
    return _squareSumOfDiff / (_nbIter - 1);
}

double MC_Simulation::stdDeviation() const
{
    return sqrt(variance());
}

size_t MC_Simulation::nbObservations() const
{
    return _nbIter;
}

seconds MC_Simulation::timeOfComputation() const
{
    return (std::chrono::system_clock::now() - _begin);
}
