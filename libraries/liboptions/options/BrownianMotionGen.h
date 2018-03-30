#ifndef BROWNIANMOTIONGEN_H
#define BROWNIANMOTIONGEN_H

#include <vector>

#include "GaussianRandomVariable.h"


/*!
 * @brief Class for Brownian Motion generators
 */
class BrownianMotionGen
{
public:

    /*!
     * @brief Contructor for the BrownianMotionGen class
     * @details This constructor takes a vector of double as argument
     * representing the discretization of the interval over which the Brownian
     * motion will be generated
     *
     * @param   indices the indices of the partition of the time interval
     */
    BrownianMotionGen(const std::vector<double>& partition);

    /*!
     * @brief Contructor for the BrownianMotionGen class
     * @details Same as above, but initialization with a rvalue
     *
     * @param   indices the indices of the partition of the time interval
     */
    BrownianMotionGen(std::vector<double>&& partition);

    /*!
     * @brief Contructor for the BrownianMotionGen class
     * @details Initialize the generator for a regular partition of the interval
     *
     * @param   T   the time interval
     * @param   N   the number of subdivisions
     */
    BrownianMotionGen(double T, size_t N);

    ~BrownianMotionGen();

    /*!
     * @brief Accessor on the partition over which the generator simulates the
     * Brownian motion
     *
     * @return the partition of the generator
     */
    const std::vector<double>& partition() const;

    /*!
     * @brief Simulates a path for the Brownian motion
     *
     * @return the generated Brownian motion
     */
    std::vector<double> operator()();

private:
    std::vector<double> _partition;
    GaussianRV _Z;
};

/*!
* @brief Creates a regular partition over the interval [0, T]
*
* @param    T   the time interval
* @param    N   the number of subdivisions
* @return the partition over T
*/
std::vector<double> regularPartition(double T, size_t N);


#endif // BROWNIANMOTIONGEN_H
