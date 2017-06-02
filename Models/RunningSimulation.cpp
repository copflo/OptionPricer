#include "RunningSimulation.h"

RunningSimulation::RunningSimulation()
    : _nbIter(0)
    , _mean(0.0)
    , _squareSumOfDiff(0.0)
    , _begin(std::chrono::system_clock::now())
{
}

RunningSimulation::~RunningSimulation()
{
}

void RunningSimulation::update(double value)
{
    const double bufferMean = _mean;
    _mean = _mean + (value - _mean) / (++_nbIter);

    if (_nbIter > 1) {
        _squareSumOfDiff = _squareSumOfDiff + (value - bufferMean) * (value - _mean);
    }
}

double RunningSimulation::mean() const
{
    return _mean;
}

double RunningSimulation::variance() const
{
    return _squareSumOfDiff / (_nbIter - 1);
}

double RunningSimulation::stdDeviation() const
{
    return sqrt(variance());
}

size_t RunningSimulation::nbObservations() const
{
    return _nbIter;
}

seconds RunningSimulation::timeOfComputation() const
{
    return (std::chrono::system_clock::now() - _begin);
}
