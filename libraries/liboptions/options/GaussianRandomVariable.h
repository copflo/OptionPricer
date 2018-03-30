#ifndef GaussianRandomVariable_h
#define GaussianRandomVariable_h

#include <random>


/*!
 * @brief Class for generating random numbers following a Gaussian distribution
 */
class GaussianRV
{
public:

    /*!
     * @brief Constructor for the GaussianRV class
     *
     * @param   mean    the mean of the random variable. Set to 0 by default
     * @param   std_dev the standard deviation. Set to 1 by default
     */
    GaussianRV(double mean = 0.0, double std_dev = 1.0);

    ~GaussianRV();

    /*!
     * @brief Generates a random number
     *
     * @return a generated random number following the distribution
     */
    double operator()();

private:
    std::mt19937_64 _generator;
    std::normal_distribution<double> _distribution;
};


#endif // GaussianRandomVariable_h
