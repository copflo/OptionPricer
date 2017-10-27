#include "PathIndependentOption.h"


PathIndependentOption::PathIndependentOption(OptionNature* nature, int maturity, double strike)
    : Option(nature, maturity)
    , FixedStrike(strike)
{
}

PathIndependentOption::~PathIndependentOption()
{
}

void PathIndependentOption::print(std::ostream& os) const
{
    Option::print(os);
    os << "Strike: " << _strike << std::endl;
}
