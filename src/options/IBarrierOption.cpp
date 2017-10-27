#include "BarrierOption.h"

IBarrierOption::IBarrierOption(OptionNature* nature, int maturity, int obsFreq, double strike, double barrier)
    : PathDependentOption(nature, maturity, obsFreq)
    , FixedStrike(strike)
    , _barrier(barrier)
{
}

IBarrierOption::~IBarrierOption()
{
}

double IBarrierOption::getBarrier() const
{
    return _barrier;
}

std::string IBarrierOption::style() const
{
    return "Barrier";
}
