#include <algorithm>

#include "PathGenerator.h"


SpotPathGenerator::SpotPathGenerator(double r, const Volatility& vol, size_t nbObs, size_t obsPeriod)
    : BlackScholesGen(r, vol)
    , _br(nbObs + 1, static_cast<double>(obsPeriod) / vol.period())
{
}

SpotPathGenerator::SpotPathGenerator(double r, const Volatility& vol, const std::vector<double>& indices)
    : BlackScholesGen(r, vol)
    , _br(indices)
{
}

SpotPathGenerator::SpotPathGenerator(double r, const Volatility& vol, std::vector<double>&& indices)
    : BlackScholesGen(r, vol)
    , _br(indices)
{
}

SpotPathGenerator::~SpotPathGenerator()
{
}

std::vector<double> SpotPathGenerator::operator()(double s0)
{
    auto B = _br();
    std::vector<double> path(B.size());
    path[0] = s0;
    for(size_t idx = 1; idx < B.size(); ++idx) {
        const double T = _br.indices()[idx] - _br.indices()[0];
        path[idx] = spot(s0, T, B[idx]);
    }
    return path;
}
