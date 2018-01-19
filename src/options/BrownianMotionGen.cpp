#include "BrownianMotionGen.h"


BrownianMotionGen::BrownianMotionGen(const std::vector<double>& indices)
    : _indices(indices)
{
}

BrownianMotionGen::BrownianMotionGen(std::vector<double>&& indices)
    : _indices(indices)
{
}

BrownianMotionGen::BrownianMotionGen(size_t nbObs, double obsPeriod)
    : _indices(constIncrementVect(nbObs, obsPeriod))
{
}

BrownianMotionGen::~BrownianMotionGen()
{
}

const std::vector<double>& BrownianMotionGen::indices() const
{
    return _indices;
}

std::vector<double> BrownianMotionGen::operator()()
{
    std::vector<double> traj(_indices.size());
    traj[0] = 0.;
    for(size_t idx = 1; idx < traj.size(); ++idx) {
        traj[idx] = sqrt(_indices[idx] - _indices[idx - 1]) * _Z() + traj[idx - 1];
    }
    return traj;
}

std::vector<double> constIncrementVect(size_t size, double increment)
{
    std::vector<double> v(size);
    for(size_t n = 1; n < size; ++n) {
        v[n] = n * increment;
    }
    return v;
}
