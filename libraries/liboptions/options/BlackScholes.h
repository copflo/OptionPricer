#ifndef BlackSholes_h
#define BlackSholes_h

#include "AmericanOption.h"
#include "AssetOrNothingOption.h"
#include "CashOrNothingOption.h"
#include "EuropeanOption.h"

#include "greeks.h"
#include "Volatility.h"


/*!
 * @brief Class for the Black-Scholes(-Merton) model
 */
class BlackScholes
{
public:
    
    /*!
     * @brief Contructor for the BlackScholes class
     *
     * @param   vol the volatility of the underlying asset
     */
    BlackScholes(const Volatility& vol);

    ~BlackScholes();

    /*!
     * @brief Computes the price of a European option
     *
     * @param   r       the riskless rate
     * @param   s0      the initial spot
     * @param   option  the option to price
     * @return the price of the option
     */
    double price(double r, double s0, const EuropeanOption& option) const;

    /*!
     * @brief Computes the price of a cash-or-nothing option
     *
     * @param   r       the riskless rate
     * @param   s0      the initial spot
     * @param   option  the option to price
     * @return the price of the option
     */
    double price(double r, double s0, const CashOrNothingOption& option) const;

    /*!
     * @brief Computes the price of an asset-or-nothing option
     *
     * @param   r       the riskless rate
     * @param   s0      the initial spot
     * @param   option  the option to price
     * @return the price of the option
     */
    double price(double r, double s0, const AssetOrNothingOption& option) const;

    /*!
     * @brief Computes the greeks of an option
     *
     * @tparam  Opt     the option class
     *
     * @param   r       the riskless rate
     * @param   s0      the initial spot
     * @param   option  the option
     * @return the greeks of the option
     */
    template<class Opt>
    Greeks greeks(double r, double s0, const Opt& option) const;

    /*!
     * @brief Computes the delta of a European option
     *
     * @param   r       the riskless rate
     * @param   s0      the initial spot
     * @param   option  the option
     * @return the delta of the option
     */
    double delta(double r, double s0, const EuropeanOption& option) const;

    /*!
     * @brief Computes the gamma of a European option
     *
     * @param   r       the riskless rate
     * @param   s0      the initial spot
     * @param   option  the option
     * @return the gamma of the option
     */
    double gamma(double r, double s0, const EuropeanOption& option) const;

    /*!
     * @brief Computes the vega of a European option
     *
     * @param   r       the riskless rate
     * @param   s0      the initial spot
     * @param   option  the option
     * @return the vega of the option
     */
    double vega(double r, double s0, const EuropeanOption& option) const;

    /*!
     * @brief Computes the theta of a European option
     *
     * @param   r       the riskless rate
     * @param   s0      the initial spot
     * @param   option  the option
     * @return the theta of the option
     */
    double theta(double r, double s0, const EuropeanOption& option) const;

    /*!
     * @brief Computes the rho of a European option
     *
     * @param   r       the riskless rate
     * @param   s0      the initial spot
     * @param   option  the option
     * @return the rho of the option
     */
    double rho(double r, double s0, const EuropeanOption& option) const;

private:

    /*!
     * @brief Computes d1
     *
     * @param   r   the riskless rate
     * @param   s0  the initial spot
     * @param   K   the strike
     * @param   T   the time until maturity
     * @return d1
     */
    double d1(double r, double s0, double K, double T) const;

    /*!
     * @brief Computes d2
     *
     * @param   r   the riskless rate
     * @param   s0  the initial spot
     * @param   K   the strike
     * @param   T   the time until maturity
     * @return d2
     */
    double d2(double r, double s0, double K, double T) const;

    /*!
     * @brief Computes d1 and d2
     *
     * @param   r   the riskless rate
     * @param   s0  the initial spot
     * @param   K   the strike
     * @param   T   the time until maturity
     * @return the pair d1, d2
     */
    std::pair<double, double> d1_d2(double r, double s0, double K, double T) const;

private:
    Volatility _vol;
};


template<class Opt>
Greeks BlackScholes::greeks(double r, double s0, const Opt& option) const
{
    return Greeks(delta(r, s0, option),
                  vega(r, s0, option),
                  theta(r, s0, option),
                  rho(r, s0, option),
                  gamma(r, s0, option));
}


#endif // BlackSholes_h
