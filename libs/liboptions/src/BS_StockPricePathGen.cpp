#include <algorithm>

#include "BS_StockPricePathGen.h"


BS_StockPricePathGen::BS_StockPricePathGen(double r, const Volatility& vol, double T, size_t N)
    : BlackScholesGen(r, vol)
    , _br(T, N)
{
}

BS_StockPricePathGen::BS_StockPricePathGen(double r, const Volatility& vol, const std::vector<double>& partition)
    : BlackScholesGen(r, vol)
    , _br(partition)
{
}

BS_StockPricePathGen::BS_StockPricePathGen(double r, const Volatility& vol, std::vector<double>&& partition)
    : BlackScholesGen(r, vol)
    , _br(partition)
{
}

BS_StockPricePathGen::~BS_StockPricePathGen()
{
}

std::vector<double> BS_StockPricePathGen::operator()(double s0)
{
    const auto B = _br();
    std::vector<double> path(B.size());
    path[0] = s0;
    for(size_t idx = 1; idx < B.size(); ++idx) {
        const double T = _br.partition()[idx] - _br.partition()[0];
        path[idx] = spot(s0, T, B[idx]);
    }
    return path;
}
