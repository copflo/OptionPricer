#ifndef BLACKSCHOLESGEN_H
#define BLACKSCHOLESGEN_H

#include "Volatility.h"


/*!
 * @brief Base class for stock prices generators following the Black-Scholes
 * model
 */
class BlackScholesGen
{
public:
    virtual ~BlackScholesGen();

protected:

    /*!
     * @brief Constructor for the BlackScholesGen class
     *
     * @param   r   the riskless rate
     * @param   vol the volatility of the underlying asset
     */
    BlackScholesGen(double r, const Volatility& vol);

    /*!
     * @brief Computes the asset's value at time T for an initial value s0 and a
     * generated brownian motion
     *
     * @param   s0  the initial asset's value
     * @param   t   the time at which the future price is wanted
     * @param   Bt  a generated brownian motion over T
     * @return the asset's value at T
     */
    double spot(double s0, double t, double Bt);

protected:
    double     _riskfreeRate;
    Volatility _vol;
};


#endif // BLACKSCHOLESGEN_H
