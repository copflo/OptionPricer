#ifndef TimeLimit_h
#define TimeLimit_h

#include "StopSimulation.h"

class TimeLimit 
    : public StopSimulation
{
public:
            TimeLimit (double calculusTime);
    virtual ~TimeLimit();

    virtual bool stop(const RunningSimulation& simulation) const;

private:
    const seconds _calculusTime;
};

#endif /* TimeLimit_h */