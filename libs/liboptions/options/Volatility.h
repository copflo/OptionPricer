#ifndef VOLATILITY_H
#define VOLATILITY_H

#include <iostream>


/*!
 * @brief Class representing a static volatility
 */
class Volatility
{
public:

    /*!
     * @brief Constructor for the Volatility class
     * 
     * @param   value   the value of the volatility
     * @param   days    the number of days of the volatility
     */
    Volatility(double value, size_t days = 252);

    ~Volatility();

    /*!
     * @brief Getter on the value of the volatility
     * 
     * @return the value of the volatility
     */
    double value() const;

    /*!
     * @brief Computes the value of the volatility over a period
     * 
     * @param   period  the period upon which the value of the
     *                  volatility is wanted
     * @return the value of the volatility over the period
     */
    double value(size_t period) const;
    
    /*!
     * @brief Getter on the period of the volatility
     * 
     * @return the period of the volatility
     */
    size_t period() const;

    /*!
     * @brief Build a new and equivalent volatility, but on the
     * specified period
     * 
     * @param   period  the period upon which the new volatility
     *                  is wanted
     * @return the new volatility on the period
     */ 
    Volatility volatility(size_t period) const;

private:
    double _value;
    size_t _period;
};

/*!
 * @brief Overloads the << operator for the Volatility class
 * 
 * @param   os  the output stream
 * @param   vol the volatility to print in os
 */
std::ostream& operator<<(std::ostream& os, const Volatility& vol);


#endif // VOLATILITY_H
