#include "GaussianRandomVariable.h"


GaussianRV::GaussianRV(double mean, double std_dev)
    : _distribution(mean, std_dev)
{
}

GaussianRV::~GaussianRV()
{
}

double GaussianRV::operator()()
{
    return _distribution(_generator);
}
