#include <sstream>
#include <stdexcept>

#include "Volatility.h"

Volatility::Volatility(double value, int period)
    : _value(value)
    , _period(period)
{
    if ((0.0 < _value) == false) {
        throw std::runtime_error("Volatility with null value");
    }
}

Volatility::~Volatility()
{
}

double Volatility::value(int period) const
{
    return _value * sqrt(static_cast<double>(period) / _period);
}

double Volatility::value() const
{
    return _value;
}

int Volatility::period() const
{
    return _period;
}

Volatility Volatility::volatility(int period) const
{
    return Volatility(value(period), period);
}


std::ostream& operator<<(std::ostream& os, const Volatility& vol)
{
    os << vol.value() << " on " << vol.period() << " days";
    return os;
}
