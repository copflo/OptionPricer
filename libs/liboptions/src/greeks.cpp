#include "greeks.h"


Greeks::Greeks(double delta, double vega, double theta, double rho, double gamma)
    : _delta(delta)
    , _vega(vega)
    , _theta(theta)
    , _rho(rho)
    , _gamma(gamma)
{
}

Greeks::~Greeks()
{
}

double Greeks::delta() const
{
    return _delta;
}

double Greeks::vega() const
{
    return _vega;
}

double Greeks::theta() const
{
    return _theta;
}

double Greeks::rho() const
{
    return _rho;
}

double Greeks::gamma() const
{
    return _gamma;
}

std::ostream& operator<<(std::ostream& os, const Greeks& greeks)
{
    os << "delta : " << greeks.delta() << std::endl;
    os << "vega : " << greeks.vega() << std::endl;
    os << "theta : " << greeks.theta() << std::endl;
    os << "rho : " << greeks.rho() << std::endl;
    os << "gamma : " << greeks.gamma() << std::endl;

    return os;
}

