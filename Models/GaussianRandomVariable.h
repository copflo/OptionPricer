#ifndef GaussianRandomVariable_h
#define GaussianRandomVariable_h

#include <random>

class GaussianRV
{
public:
    GaussianRV (double mean = 0.0, double std_dev = 1.0);
    ~GaussianRV();

    double operator()();

private:
    std::mt19937_64                  _generator;
    std::normal_distribution<double> _distribution;
};

#endif /* GaussianRandomVariable_h */