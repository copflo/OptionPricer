#ifndef PUT_H
#define PUT_H

#include "OptionNature.h"


/*!
 * @brief Class for put payoffs
 */
class Put
    : public OptionNature
{
public:

    /*!
     * @brief Indicates if the type of payoff is a call
     *
     * @return false
     */
    virtual bool isCall() const;

    /*!
     * @brief Indicates if the type of payoff is a put
     *
     * @return true
     */
    virtual bool isPut() const;

    /*!
     * @brief Gives the payoff of a call for a given spot and a given strike
     *
     * @return max(strike - spot, 0.0)
     */
    virtual double payoff(double spot, double strike) const;

    /*!
     * @brief Gives the string representation of a call
     *
     * @return \"put\"
     */
    virtual std::string toString() const;
};


#endif // PUT_H
