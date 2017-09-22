#ifndef NbObs_h
#define NbObs_h

#include "StopSimulation.h"


class NbObs
    : public StopSimulation
{
public:
            NbObs (size_t nbObs);
    virtual ~NbObs();

    virtual bool stop(const RunningStats& stats) const;

private:
    const size_t _nbObs;
};


#endif //NbObs_h
