#ifndef SpotPathGenerator_h
#define SpotPathGenerator_h

#include <vector>

#include "BlackScholesSpot.h"


class SpotPathGenerator
{
public:
    SpotPathGenerator(size_t            nbObs,
                      double            risklessRate,
                      const Volatility& vol, 
                      int               obsPeriod);

    ~SpotPathGenerator();

    std::vector<double> operator()(double currentSpot);

private:
    size_t           _nbObs;
    BlackScholesSpot _spot;
};


#endif // SpotPathGenerator_h
