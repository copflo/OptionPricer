#ifndef AccuracyConfidence_h
#define AccuracyConfidence_h

#include "StopSimulation.h"


class AccuracyConfidence 
    : public StopSimulation
{
public:
            AccuracyConfidence (double accuracy, double confidence);
    virtual ~AccuracyConfidence();

    virtual bool stop(const RunningStats& stats) const;

private:
    const double _ratio;
};


#endif /* AccuracyConfidence_h */
