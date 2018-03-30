#include <cmath>

#include "Option.h"


Option::Option(OptionNature* nature, size_t maturity)
    : _nature(nature)
    , _maturity(maturity)
{
}

Option::~Option()
{
}

bool Option::isCall() const
{
    return _nature->isCall();
}

bool Option::isPut() const
{
    return _nature->isPut();
}

size_t Option::maturity() const
{
    return _maturity;
}

void Option::print(std::ostream& os) const
{
    os << style() << " " << _nature->toString() << std::endl;
    os << "Maturity: " << _maturity  << " days" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Option& option)
{
    option.print(os);
    return os;
}
