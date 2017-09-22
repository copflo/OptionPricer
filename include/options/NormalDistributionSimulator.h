#ifndef NormalDistributionSimulator_h
#define NormalDistributionSimulator_h

#include <random>


class NormalDistributionSimulator
{
public:
    NormalDistributionSimulator(double mean = 0.0, double std_dev = 1.0);
    ~NormalDistributionSimulator();

    double simulate();

private:
    std::mt19937_64                  _generator;
    std::normal_distribution<double> _distribution;
};


#endif // NormalDistributionSimulator_h
