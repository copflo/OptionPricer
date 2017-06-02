#ifndef StopSimulation_h
#define StopSimulation_h

#include "RunningSimulation.h"

class StopSimulation
{
public:
            StopSimulation ();
    virtual ~StopSimulation();

    virtual bool stop(const RunningSimulation& simulation) const = 0;
};

#endif /* StopSimulation_h */