#ifndef OptionSensitivity_h
#define OptionSensitivity_h

#include <iostream>

class OptionSensitivity
{
public:
    OptionSensitivity (double delta, double vega, double theta, double rho, double gamma);
    ~OptionSensitivity();

    double getDelta() const;
    double getVega()  const;
    double getTheta() const;
    double getRho()   const;
    double getGamma() const;

private:
    double _delta;
    double _vega;
    double _theta;
    double _rho;
    double _gamma;
};

std::ostream& operator<<(std::ostream& os, const OptionSensitivity& sensitivity);

#endif /* OptionSensitivity_h */