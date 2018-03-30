#ifndef BS_StockPriceGen_h
#define BS_StockPriceGen_h

#include "BlackScholesGen.h"
#include "GaussianRandomVariable.h"
#include "Volatility.h"


/*!
 * @brief Class for generators of stock prices according to Black-Scholes model
 */
class BS_StockPriceGen
    : public BlackScholesGen
{
public:

    /*!
     * @brief Constructor for the BS_StockPriceGen class
     *
     * @param   r       the risfree rate
     * @param   days    the number of days during which the stock price will evolve
     * @param   vol     the volatility of the asset
     */
    BS_StockPriceGen(double r, size_t days, const Volatility& vol);

    ~BS_StockPriceGen();

    /*!
     * @brief Simulates a future stock price from a given initial stock value
     *
     * @param   s0  the initial stock price
     * @return the generated stock value
     */
    double operator()(double s0);

private:
    double     _T;
    GaussianRV _Z;
};


#endif // BS_StockPriceGen_h
