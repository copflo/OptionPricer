#ifndef Call_H
#define Call_H

#include "OptionNature.h"


/*!
 * @brief Class for call payoffs
 */
class Call
    : public OptionNature
{
public:

    /*!
     * @brief Indicates if the type of payoff is a call
     *
     * @return true
     */
    virtual bool isCall() const;

    /*!
     * @brief Indicates if the type of payoff is a put
     *
     * @return false
     */
    virtual bool isPut() const;

    /*!
     * @brief Gives the payoff of a call for a given spot and a given strike
     *
     * @return max(spot - strike, 0.0)
     */
    virtual double payoff(double spot, double strike) const;

    /*!
     * @brief Gives the string representation of a call
     *
     * @return \"call\"
     */
    virtual std::string toString() const;
};


#endif // Call_H
