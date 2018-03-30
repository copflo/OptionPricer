#ifndef GREEKS_H
#define GREEKS_H

#include <iostream>


/*!
 * @brief Class representing the Greeks of an option
 */
class Greeks
{
public:

    /*!
     * @brief Contructor for the Greeks class
     *
     * @param   delta   the delta
     * @param   vega    the vega
     * @param   theta   the theta
     * @param   rho     the rho
     * @param   gamma   the gamma
     */
    Greeks(double delta, double vega, double theta, double rho, double gamma);
    
    ~Greeks();

    /*!
     * @brief Accessor on the delta
     *
     * @return the delta
     */
    double delta() const;

    /*!
     * @brief Accessor on the gamma
     *
     * @return the gamma
     */
    double gamma() const;

    /*!
     * @brief Accessor on the vega
     *
     * @return the vega
     */
    double vega() const;

    /*!
     * @brief Accessor on the theta
     *
     * @return the theta
     */
    double theta() const;

    /*!
     * @brief Accessor on the rho
     *
     * @return the rho
     */
    double rho() const;

private:
    double _delta;
    double _vega;
    double _theta;
    double _rho;
    double _gamma;
};

/*!
 * @brief Prints the greeks in the output stream
 *
 * @param   os      the output stream
 * @param   greeks  the Greeks
 */
std::ostream& operator<<(std::ostream& os, const Greeks& greeks);


#endif // GREEKS_H
