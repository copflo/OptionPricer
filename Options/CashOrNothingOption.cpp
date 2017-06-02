#include "CashOrNothingOption.h"

CashOrNothingOption::CashOrNothingOption(Option::Nature nature, 
                                         int            maturity, 
                                         double         strike, 
                                         double         rebate)
    : DigitalOption(nature, maturity, strike)
    , _rebate(rebate)
{
}

CashOrNothingOption::~CashOrNothingOption()
{
}

double CashOrNothingOption::rebate() const
{
    return _rebate;
}

std::string CashOrNothingOption::style() const
{
    return "Cash-or-nothing";
}

double CashOrNothingOption::payoff(double spot) const
{
    return successfulBet(spot)? _rebate : 0.0;
}

void CashOrNothingOption::print(std::ostream& os) const
{
    DigitalOption::print(os);
    os << "Rebate: " << _rebate << std::endl;
}
