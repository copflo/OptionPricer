#ifndef BarrierOption_h
#define BarrierOption_h

#include "Down.h"
#include "IBarrierOption.h"
#include "KnockIn.h"
#include "KnockOut.h"
#include "Up.h"

template<class Direction, class Knock>
class BarrierOption
    : public IBarrierOption
{
public:
    BarrierOption(Nature nature, int maturity, int obsFreq, double strike, double barrier)
        : IBarrierOption(nature, maturity, obsFreq, strike, barrier)
    {
    }

    virtual double payoff(const std::vector<double>& spot_path) const
    {
        return Knock::activated(Direction::barrierIsCrossed(_barrier, spot_path))? 
            Option::payoff(spot_path.back(), _strike) : 0.0;
    }

    virtual void print(std::ostream& os) const
    {
        Option::print(os);
        os << Direction::toString() << " and " << Knock::toString() << std::endl;
        os << "Strike: " << _strike << std::endl;
        os << "Barrier: " << _barrier << std::endl;
    }
};

typedef BarrierOption<Up, KnockIn> UpInBarrierOption;
typedef BarrierOption<Down, KnockIn> DownInBarrierOption;
typedef BarrierOption<Up, KnockOut> UpOutBarrierOption;
typedef BarrierOption<Down, KnockOut> DownOutBarrierOption;

#endif /* BarrierOption_h */