#include <cmath>

#include "RunningStats.h"


RunningStats::RunningStats()
    : _nbIter(0)
    , _mean(0.0)
    , _squareSumOfDiff(0.0)
    , _begin(std::chrono::system_clock::now())
{
}

RunningStats::~RunningStats()
{
}

void RunningStats::update(double value)
{
    const double bufferMean = _mean;
    _mean = _mean + (value - _mean) / (++_nbIter);
    if (_nbIter > 1) {
        _squareSumOfDiff += (value - bufferMean) * (value - _mean);
    }
}

double RunningStats::mean() const
{
    return _mean;
}

double RunningStats::variance() const
{
    return _squareSumOfDiff / (_nbIter - 1);
}

double RunningStats::stdDeviation() const
{
    return sqrt(variance());
}

size_t RunningStats::nbObservations() const
{
    return _nbIter;
}

seconds RunningStats::timeOfComputation() const
{
    return (std::chrono::system_clock::now() - _begin);
}
