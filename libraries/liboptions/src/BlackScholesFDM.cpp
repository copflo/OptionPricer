#include <cmath>
#include <fstream>

#include "BlackScholesFDM.h"


std::vector<double> BlackScholesFDM::mesh(size_t size, double step)
{
    std::vector<double> m(size, 0.);
    for (size_t idx = 1; idx < size; ++idx) {
        m[idx] = idx * step;
    }
    return m;
}

std::vector<double> BlackScholesFDM::initialCdt(const VanillaOption& option, 
                                                const std::vector<double>& s)
{
    std::vector<double> v(s);
    for(double& sj : v) {
        sj = option.payoff(sj);
    }
    return v;
}

double BlackScholesFDM::leftBoundaryCdt(const EuropeanOption& option, double t, double r)
{
    if (option.isCall()) {
        return 0.0;
    }
    return option.strike() * exp(-r * t);
}

double BlackScholesFDM::rightBoundaryCdt(const EuropeanOption& option,
                                         double t,
                                         double Smax,
                                         double r)
{
    if (option.isCall()) {
        return Smax - option.strike() * exp(-r * t);
    }
    return 0.0;
}

double BlackScholesFDM::alpha(size_t j, double sigma2, double dt, double r)
{
    return 0.5 * (sigma2 * j*j * dt - r * j*dt);
}
double BlackScholesFDM::beta(size_t j, double sigma2, double dt, double r)
{
    return 1. - sigma2 * j*j * dt - r * dt;
}
double BlackScholesFDM::gamma(size_t j, double sigma2, double dt, double r)
{
    return 0.5 * (sigma2 * j*j * dt + r * j*dt);
}


BlackScholesFDM::BlackScholesFDM(const Volatility& vol, size_t J, size_t N)
    : _vol(vol)
    , _J(J)
    , _N(N)
{
}

template<>
void BlackScholesFDM::writePriceSurface(double r, 
                                        const EuropeanOption& option, 
                                        const std::string& fileName) const
{
    std::ofstream file(fileName);
    writePriceSurface(r, option, file);
}

std::vector<std::array<double, 3>> BlackScholesFDM::priceSurface(double r, 
                                                                 const EuropeanOption& option) const
{
    std::vector<std::array<double, 3>> surface;
    writePriceSurface(r, option, surface);
    return surface;
}

template<>
void BlackScholesFDM::writeCoordinates(double t, 
                                       const std::vector<double>& s, 
                                       const std::vector<double>& v,
                                       std::vector<std::array<double, 3>>& container) const
{
    for(size_t j = 0; j < _J + 1; ++j) {
        container.push_back({ t, s[j], v[j] });
    }
}