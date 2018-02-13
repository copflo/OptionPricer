#ifndef BS_StockPricePathGen_h
#define BS_StockPricePathGen_h

#include <vector>

#include "BlackScholesGen.h"
#include "BrownianMotionGen.h"


class BS_StockPricePathGen
    : public BlackScholesGen
{
public:
    BS_StockPricePathGen (double r, const Volatility& vol, size_t nbObs, size_t obsPeriod);
    BS_StockPricePathGen (double r, const Volatility& vol, const std::vector<double>& indices);
    BS_StockPricePathGen (double r, const Volatility& vol, std::vector<double>&& indices);
    ~BS_StockPricePathGen();

    std::vector<double> operator()(double s0);

private:
    BrownianMotionGen _br;
};


#endif // BS_StockPricePathGen_h
