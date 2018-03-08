#ifndef BS_StockPricePathGen_h
#define BS_StockPricePathGen_h

#include <vector>

#include "BlackScholesGen.h"
#include "BrownianMotionGen.h"


/*!
 * @brief Class for generators of stock prices paths according to Black-Scholes
 * model
 */
class BS_StockPricePathGen
    : public BlackScholesGen
{
public:

    /*!
     * @brief Constructor for the BS_StockPricePathGen class
     * @details This contructor takes as arguments the period over which the
     * path will be generated with a number of subdivisions for a regular
     * partition
     *
     * @param   r   the risfree rate
     * @param   vol the volatility of the asset
     * @param   T   the time interval
     * @param   N   the number of subdivisions
     */
    BS_StockPricePathGen(double r, const Volatility& vol, double T, size_t N);

    /*!
     * @brief Constructor for the BS_StockPricePathGen class
     * @details This contructor takes as argument the partition for the
     * generation of the path
     *
     * @param   r           the risfree rate
     * @param   vol         the volatility of the asset
     * @param   partition   the partition for the path to be generated
     */
    BS_StockPricePathGen(double r,
                         const Volatility& vol,
                         const std::vector<double>& partition);

    /*!
    * @brief Constructor for the BS_StockPricePathGen class
    * @details Same as above, but for a rvalue partition
    *
    * @param   r           the risfree rate
    * @param   vol         the volatility of the asset
    * @param   partition   the partition for the path to be generated
    */
    BS_StockPricePathGen(double r,
                         const Volatility& vol,
                         std::vector<double>&& partition);

    ~BS_StockPricePathGen();


    /*!
    * @brief Simulates a stock price path from a given initial stock value
    *
    * @param   s0  the initial stock price
    * @return the generated stock value
    */
    std::vector<double> operator()(double s0);

private:
    BrownianMotionGen _br;
};


#endif // BS_StockPricePathGen_h
