#include <cmath>

#include "Option.h"


Option::Option(Nature nature, int maturity)
    : _nature(nature)
    , _maturity(maturity)
{
}

Option::~Option()
{
}

bool Option::isCall() const
{
    return _nature == CALL;
}

bool Option::isPut() const
{
    return _nature == PUT;
}

int Option::maturity() const
{
    return _maturity;
}

void Option::print(std::ostream& os) const
{
    os << style() << " " << nature() << std::endl;
    os << "Maturity: " << _maturity  << " days" << std::endl;
}

std::string Option::nature() const
{
    if (isCall()) {
        return "call";
    }

    return "put";
}

double Option::payoff(double spot, double strike) const
{
    if (isCall()) {
        return fmax(spot - strike, 0.0);
    }

    return fmax(strike - spot, 0.0);
}

std::ostream& operator<<(std::ostream& os, const Option& option)
{
    option.print(os);
    return os;
}
