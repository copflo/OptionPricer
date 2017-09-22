#ifndef StopSimulation_h
#define StopSimulation_h

#include "RunningStats.h"


class StopSimulation
{
public:
            StopSimulation ();
    virtual ~StopSimulation();

    virtual bool stop(const RunningStats& stats) const = 0;
};


#endif // StopSimulation_h
