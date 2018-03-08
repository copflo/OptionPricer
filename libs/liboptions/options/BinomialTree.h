#ifndef BinomialTree_h
#define BinomialTree_h

#include "AmericanOption.h"
#include "EuropeanOption.h"


/*!
 * @brief Class for the binomial tree model (Cox-Ross-Rubinstein)
 */
class BinomialTree
{
private:

    /*
     * @brief Computes the binomial value of an option
     *
     * @param   r           the riskless rate
     * @param   p           the probability of getting "up" under the
     *                      risk-neutral probability
     * @param   upSpot      the spot if event "up" occurs
     * @param   downSpot    the spot if event "down" occurs
     * @return the binomial value
     */
    static double binomialValue(double r, double p, double upSpot, double downSpot);

public:

    /*!
     * @brief Contructor for the BinomialTree class
     *
     * @param   up      the percentage increase if event "up" occurs
     * @param   down    the percentage decrease if event "down" occurs
     * @param   nbSteps the maturity of the market
     */
    BinomialTree (double up, double down, size_t nbSteps);

    virtual ~BinomialTree();

    /*!
     * @brief Computes the price of an option
     *
     * @tparam  Opt the option class
     *
     * @param   r       the riskless rate
     * @param   s0      the initial spot
     * @param   option  the option to price
     */
    template<class Opt>
    double price(double r, double s0, const Opt& option) const;

private:

    /*!
     * @brief Computes the probability of getting "up" under p*
     *
     * @param   r   the riskless rate
     */
    double neutralProba(double r) const;

    /*!
     * @brief Computes the value of an American option at a given time step
     *
     * @param   option  the option
     * @param   r       the riskless rate
     * @param   p       the probability of getting "up" under the risk-neutral
     *                  probability
     * @param   s0      the initial spot
     * @param   stepNo  the step at which the value of the option is wanted
     * @return the value of the option
     */
    double optionValue(const AmericanOption& option,
                       double r,
                       double p,
                       double s0,
                       size_t stepNo) const;

    /*!
    * @brief Computes the value of a Euopean option at a given time step
    *
    * @param   option  the option
    * @param   r       the riskless rate
    * @param   p       the probability of getting "up" under the risk-neutral
    *                  probability
    * @param   s0      the initial spot
    * @param   stepNo  the step at which the value of the option is wanted
    * @return the value of the option
    */
    double optionValue(const EuropeanOption& option,
                       double r,
                       double p,
                       double s0,
                       size_t stepNo) const;

private:
    const double _up;
    const double _down;
    const size_t _nbSteps;
};


template<class Opt>
double BinomialTree::price(double r, double s0, const Opt& option) const
{
    if (!(_down < r) || !(r < _up)) {
        throw std::runtime_error("r must be like: decrease < r < increase for an arbitrageless market");
    }
    return optionValue(option, r, neutralProba(r), s0, 0);
}


#endif // BinomialTree_h
