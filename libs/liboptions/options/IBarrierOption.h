#ifndef IBarrierOption_h
#define IBarrierOption_h

#include <memory>

#include "FixedStrike.h"
#include "PathDependentOption.h"


class IBarrierOption
    : public PathDependentOption
    , public FixedStrike
{
public:
            IBarrierOption(OptionNature* nature, size_t maturity, size_t obsFreq, double strike, double barrier);
    virtual ~IBarrierOption();

            double      getBarrier() const;
    virtual std::string style     () const;

protected:
    double _barrier;
};


#endif // IBarrierOption_h
