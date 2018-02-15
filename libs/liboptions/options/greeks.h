#ifndef GREEKS_H
#define GREEKS_H

#include <iostream>


class Greeks
{
public:
    Greeks (double delta, double vega, double theta, double rho, double gamma);
    ~Greeks();

    double delta() const;
    double gamma() const;
    double vega()  const;
    double theta() const;
    double rho()   const;

private:
    double _delta;
    double _vega;
    double _theta;
    double _rho;
    double _gamma;
};

std::ostream& operator<<(std::ostream& os, const Greeks& greeks);


#endif // GREEKS_H
