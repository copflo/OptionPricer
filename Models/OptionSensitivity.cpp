#include "OptionSensitivity.h"

OptionSensitivity::OptionSensitivity(double delta, double vega, double theta, double rho, double gamma)
    : _delta(delta)
    , _vega(vega)
    , _theta(theta)
    , _rho(rho)
    , _gamma(gamma)
{
}

OptionSensitivity::~OptionSensitivity()
{
}

double OptionSensitivity::getDelta() const
{
    return _delta;
}

double OptionSensitivity::getVega() const
{
    return _vega;
}

double OptionSensitivity::getTheta() const
{
    return _theta;
}

double OptionSensitivity::getRho() const
{
    return _rho;
}

double OptionSensitivity::getGamma() const
{
    return _gamma;
}

std::ostream& operator<<(std::ostream& os, const OptionSensitivity& sensitivity)
{
    os << "delta : " << sensitivity.getDelta() << std::endl;
    os << "vega : " << sensitivity.getVega() << std::endl;
    os << "theta : " << sensitivity.getTheta() << std::endl;
    os << "rho : " << sensitivity.getRho() << std::endl;
    os << "gamma : " << sensitivity.getGamma() << std::endl;

    return os;
}

