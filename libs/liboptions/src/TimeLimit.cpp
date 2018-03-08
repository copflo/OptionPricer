#include "TimeLimit.h"


TimeLimit::TimeLimit(double calculusTime)
    : _calculusTime(calculusTime)
{
}

TimeLimit::~TimeLimit()
{
}

bool TimeLimit::stop(const MC_Simulation& sim) const
{
    return sim.timeOfComputation() >= _calculusTime;
}
