#include "TimeLimit.h"

TimeLimit::TimeLimit(double calculusTime)
    : _calculusTime(calculusTime)
{
}

TimeLimit::~TimeLimit()
{
}

bool TimeLimit::stop(const RunningSimulation& simulation) const
{
    return simulation.timeOfComputation() >= _calculusTime;
}
