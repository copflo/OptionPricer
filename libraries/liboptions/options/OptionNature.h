#ifndef OptionNature_H
#define OptionNature_H

#include <string>


/*!
 * @brief Base class for the Call and Put classes
 */
class OptionNature
{
public:

    /*!
     * @brief Indicates if the type of payoff is a call
     */
    virtual bool isCall() const = 0;

    /*!
     * @brief Indicates if the type of payoff is a put
     */
    virtual bool isPut() const = 0;

    /*!
     * @brief Gives the payoff for a given spot and a given strike
     */
    virtual double payoff(double spot, double strike) const = 0;

    /*!
     * @brief Gives a string representation of the current nature
     */
    virtual std::string toString() const = 0;
};


#endif // OptionNature_H
