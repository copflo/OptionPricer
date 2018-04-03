#ifndef BLACKSCHOLESFDM_H
#define BLACKSCHOLESFDM_H

#include <array>
#include <vector>

#include "EuropeanOption.h"
#include "Volatility.h"


class BlackScholesFDM
{
private:
    static std::vector<double> mesh(size_t size, double step);
    static std::vector<double> initialCdt(const VanillaOption& option, const std::vector<double>& s);
    static double leftBoundaryCdt(const EuropeanOption& option, double t, double r);
    static double rightBoundaryCdt(const EuropeanOption& option, double t, double Smax, double r);
    static double alpha(size_t j, double sigma2, double dt, double r);
    static double beta(size_t j, double sigma2, double dt, double r);
    static double gamma(size_t j, double sigma2, double dt, double r);

public:
    BlackScholesFDM(const Volatility& vol, size_t J, size_t N);

    template<typename Series>
    void writePriceSurface(double r, const EuropeanOption& option, Series& series) const;

    std::vector<std::array<double, 3>> priceSurface(double r, const EuropeanOption& option) const;

private:
    template<typename Series>
    void writeCoordinates(double t, 
                          const std::vector<double>& s, 
                          const std::vector<double>& v,
                          Series& series) const;

private:
    Volatility _vol;
    size_t _J;
    size_t _N;
};


template<typename Series>
void BlackScholesFDM::writePriceSurface(double r, const EuropeanOption& option, Series& series) const
{
    const double Smax = 5. * option.strike();
    const double sigma2 = _vol.value() * _vol.value();
    const double T = static_cast<double>(option.maturity()) / _vol.period();
    const double dt = T / _N;
    const double ds = Smax / static_cast<double>(_J + 1);

    std::vector<double> s = mesh(_J + 1, ds);
    std::vector<double> v = initialCdt(option, s);
    double t = 0.;
    for(size_t n = 1; n < _N; ++n) {
        writeCoordinates(T - t, s, v, series);
        std::vector<double> buffer(v);
        t += dt;
        v[0] = leftBoundaryCdt(option, t, r);
        for(size_t j = 1; j < _J; ++j) {
            const double a = alpha(j,sigma2, dt, r);
            const double b = beta(j, sigma2, dt, r);
            const double c = gamma(j, sigma2, dt, r);
            v[j] = a * buffer[j-1] + b * buffer[j] + c * buffer[j+1];
        }
        v[_J] = rightBoundaryCdt(option, t, Smax, r);
    }
    writeCoordinates(t, s, v, series);
}

template<typename Series>
void BlackScholesFDM::writeCoordinates(double t,
                                       const std::vector<double>& s,
                                       const std::vector<double>& v,
                                       Series& series) const
{
    for (size_t j = 0; j < _J + 1; ++j) {
        series << t << ' ' << s[j] << ' ' << v[j];
    }
}

template<>
void BlackScholesFDM::writeCoordinates(double t,
                                       const std::vector<double>& s,
                                       const std::vector<double>& v,
                                       std::ostream& os) const
{
    for (size_t j = 0; j < _J + 1; ++j) {
        os << t << ' ' << s[j] << ' ' << v[j] << std::endl;
    }
}

template<>
void BlackScholesFDM::writeCoordinates(double t,
                                       const std::vector<double>& s,
                                       const std::vector<double>& v,
                                       FILE& file) const
{
    for (size_t j = 0; j < _J + 1; ++j) {
        fprintf(&file, "%f %f %f\n", t, s[j], v[j]);
    }
}


#endif // BLACKSCHOLESFDM_H