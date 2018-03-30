#ifndef BLACKSCHOLESFDM_H
#define BLACKSCHOLESFDM_H

#include <vector>

#include "BlackScholes.h"
#include "Volatility.h"


class BlackScholesFDM
{
public:
    BlackScholesFDM(const Volatility& vol, double delta_S, double delta_t);

    double delta(double r, double s0, const EuropeanOption& option) const;
    double gamma(double r, double s0, const EuropeanOption& option) const;

private:
    std::vector<double> timeMesh(size_t T) const;
    std::vector<double> spotMesh(double Smax) const;

    double price(double u_n_j, double s_j, size_t n, size_t j) const;

private:
    BlackScholes _bs;
    double _delta_S;
    double _delta_t;
};


BlackScholesFDM::BlackScholesFDM(const Volatility& vol, double delta_S, double delta_t)
    : _bs(vol)
    , _delta_S(delta_S)
    , _delta_t(delta_t)
{
}

double BlackScholesFDM::delta(double r, double s0, const EuropeanOption& option) const
{
    return (_bs.price(r, s0 + _delta_S, option) - _bs.price(r, s0, option)) / _delta_S;
    // return (_bs.price(r, s0 + _delta_S, option) - _bs.price(r, s0 - _delta_S, option)) / (2. * _delta_S);
}


#endif // BLACKSCHOLESFDM_H