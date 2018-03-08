#ifndef MC_SIMULATION_H
#define MC_SIMULATION_H

#include <chrono>


typedef std::chrono::duration<double> seconds;

/*!
 * @brief Class for Monte Carlo simulations
 * @details This class stores all useful info on a running simulation and
 * provides several methods to compute statistics such as expectation, variance,
 * ...
 */
class MC_Simulation
{
public:

    /*!
     * @brief (Default) constructor for the MC_Simulation class
     */
    MC_Simulation();

    ~MC_Simulation();

    /*!
     * @brief Updates the running simulation by adding the newly generated value
     * to current statistics
     *
     * @param   value   the value to add to current statistics
     */
    void update(double value);

    /*!
     * @brief Computes the current mean for the simulation
     *
     * @return the mean for the simulation
     */
    double mean() const;

    /*!
     * @brief Computes the current variance for the simulation
     *
     * @return the variance for the simulation
     */
    double variance() const;

    /*!
     * @brief Computes the current standard deviation for the simulation
     *
     * @return the standard deviation for the simulation
     */
    double stdDeviation() const;

    /*!
     * @brief Returns the number of observations during the simulation
     *
     * @return the number of observations during the simulation
     */
    size_t nbObservations() const;

    /*!
     * @brief Computes the elapsed time since the simulation began
     *
     * @return the elapsed time since the simulation began
     */
    seconds timeOfComputation() const;

private:
    size_t _nbIter;
    double _mean;
    double _squareSumOfDiff;
    std::chrono::time_point<std::chrono::system_clock, seconds> _begin;
};


#endif // MC_SIMULATION_H
