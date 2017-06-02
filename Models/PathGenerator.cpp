#include "PathGenerator.h"

SpotPathGenerator::SpotPathGenerator(size_t            nbObs,
                                     double            risklessRate,
                                     const Volatility& vol, 
                                     int               obsPeriod)
    : _nbObs(nbObs)
    , _spot(risklessRate, obsPeriod, vol)
{
}

SpotPathGenerator::~SpotPathGenerator()
{
}

std::vector<double> SpotPathGenerator::operator()(double currentSpot)
{
    std::vector<double> path(_nbObs + 1);
    path[0] = currentSpot;

    for (size_t count = 1; count < _nbObs + 1; ++count) {
        path[count] = _spot(path[count - 1]);
    }

    return path;
}