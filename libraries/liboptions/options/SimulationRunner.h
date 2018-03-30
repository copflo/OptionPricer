#ifndef MonteCarlo_h
#define MonteCarlo_h

#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <vector>

#include "AccuracyConfidence.h"
#include "NbObs.h"
#include "TimeLimit.h"


/*!
 * @brief Class for for running Monte Carlo simulations
 * @details This class stores some conditions for stopping a simulation and handles when it stops. It also handles the
 * parallel computations with threads
 */ 
class SimulationRunner
{
private:
    
    /*!
     * @brief Computes an observation from the random estimator handling the mutex
     * 
     * @param   random  the function providing observations of the random variable
     * @param   randMtx the mutex on the random function
     */
    static double randomValue(std::function<double()> random, std::mutex& randMtx);

public:

    /*!
     * @brief Constructor for the SimulationRunner class.
     * @details This constructor takes as arguments an optional number of
     * conditions to stop a running simulation. Must have at least one condition
     * passed as arguments
     * 
     * @param    condition   the first condition to stop a running simulation
     * @param    conditions  the other optional conditions to stop a simulation
     */
    template<typename... StopConditions>
    SimulationRunner(StopSimulation* condition, StopConditions... conditions);

    /*!
     * @brief Contructor for the SimulationRunner class
     * @details This constructor takes as arguments a std::vector of conditions
     * to stop a running simulation.
     *
     * @param    conditions  the conditions to stop a simulation. Cannot be empty
     */
    SimulationRunner(std::vector<StopSimulation*>& stopConditions);

    ~SimulationRunner();

    /*!
     * @brief Runs a Monte Carlo simulation for a random variable
     * 
     * @param   random  the function providing observations of the random variable
     *                  when called
     * @return the simulation with all useful information
     */
    MC_Simulation run(std::function<double()> random) const;

    /*!
     * @brief Prints how a simulation is run in the output stream
     *
     * @param    os  the ouput stream
     */
    void print(std::ostream& os) const;

private:
    
    /*!
     * @brief Contructor for the SimulationRunner class
     * @details This constructor takes as arguments a std::initializer_list of conditions
     * to stop a running simulation. Provided for the public constructor using variadic templates
     *
     * @param    conditions  the conditions to stop a simulation. Cannot be empty
     */
    SimulationRunner(std::initializer_list<StopSimulation*> stopConditions);

    /*!
     * @brief Runs a simulation handling the mutexes
     * @details This method is used for instantiating the threads that will run during the simulation
     * 
     * @param   sim     the running simulation
     * @param   random  the function providing observations of the random variable when called
     * @param   simMtx  the mutex on the simulation
     * @param   randMtx the mutex on the random function
     */
    void runSimulation(MC_Simulation& sim,
                       std::function<double()> random,
                       std::mutex& simMtx,
                       std::mutex& randMtx) const;

    /*!
     * @brief Updates a running simulation handling the mutex on it
     * 
     * @param   sim     the running simulation
     * @param   value   the value with which the simulation will be updated
     * @param   simMtx  the mutex on the running simulation
     * @return if the simulation has been successfully updated
     */
    bool updateStats(MC_Simulation& sim,
                     double value,
                     std::mutex& simMtx) const;

    /*!
     * @brief Checks if the simulation should be stopped
     * 
     * @param   sim the running simulation
     * @return if the simulation must be stopped
     */ 
    bool stop(const MC_Simulation& sim) const;

private:
     std::vector<std::unique_ptr<StopSimulation>> _stopConditions;
};

/*!
 * @brief Overloads the << operator for the SimulationRunner class
 *
 * @param   os          the ouput stream
 * @param   simRunner   the simulation runner to print in os
 */
std::ostream& operator<<(std::ostream& os, const SimulationRunner& simRunner);


template<typename... StopConditions>
SimulationRunner::SimulationRunner(StopSimulation* condition,
                                   StopConditions... conditions)
    : SimulationRunner{ condition, conditions... }
{
}


#endif // MonteCarlo_h
