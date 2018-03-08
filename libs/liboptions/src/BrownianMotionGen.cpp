#include "BrownianMotionGen.h"


BrownianMotionGen::BrownianMotionGen(const std::vector<double>& partition)
    : _partition(partition)
{
}

BrownianMotionGen::BrownianMotionGen(std::vector<double>&& partition)
    : _partition(partition)
{
}

BrownianMotionGen::BrownianMotionGen(double T, size_t N)
    : _partition(regularPartition(T, N))
{
}

BrownianMotionGen::~BrownianMotionGen()
{
}

const std::vector<double>& BrownianMotionGen::partition() const
{
    return _partition;
}

std::vector<double> BrownianMotionGen::operator()()
{
    std::vector<double> path(_partition.size());
    for(size_t idx = 1; idx < path.size(); ++idx) {
        path[idx] = sqrt(_partition[idx] - _partition[idx - 1]) * _Z() + path[idx - 1];
    }
    return path;
}

std::vector<double> regularPartition(double T, size_t N)
{
    std::vector<double> v(N + 1);
    v[N] = T;
    for(size_t n = 1; n < N; ++n) {
        v[n] = n * T/N;
    }
    return v;
}
