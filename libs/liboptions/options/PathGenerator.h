#ifndef SpotPathGenerator_h
#define SpotPathGenerator_h

#include <vector>

#include "BlackScholesGen.h"
#include "BrownianMotionGen.h"


class SpotPathGenerator
    : public BlackScholesGen
{
public:
    SpotPathGenerator (double r, const Volatility& vol, size_t nbObs, size_t obsPeriod);
    SpotPathGenerator (double r, const Volatility& vol, const std::vector<double>& indices);
    SpotPathGenerator (double r, const Volatility& vol, std::vector<double>&& indices);
    ~SpotPathGenerator();

    std::vector<double> operator()(double s0);

private:
    BrownianMotionGen _br;
};


#endif // SpotPathGenerator_h
