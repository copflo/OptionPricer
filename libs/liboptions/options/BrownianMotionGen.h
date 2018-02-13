#ifndef BROWNIANMOTIONGEN_H
#define BROWNIANMOTIONGEN_H

#include <vector>

#include "GaussianRandomVariable.h"


class BrownianMotionGen
{
public:
    BrownianMotionGen (const std::vector<double>& indices);
    BrownianMotionGen (std::vector<double>&& indices);
    BrownianMotionGen (size_t nbObs, double obsPeriod);
    ~BrownianMotionGen();

    const std::vector<double>& indices() const;

    std::vector<double> operator()();

private:
    std::vector<double> _indices;
    GaussianRV _Z;
};

std::vector<double> constIncrementVect(size_t size, double increment);


#endif // BROWNIANMOTIONGEN_H
