#include "TimeLimit.h"


TimeLimit::TimeLimit(double calculusTime)
    : _calculusTime(calculusTime)
{
}

TimeLimit::~TimeLimit()
{
}

bool TimeLimit::stop(const RunningStats& stats) const
{
    return stats.timeOfComputation() >= _calculusTime;
}
