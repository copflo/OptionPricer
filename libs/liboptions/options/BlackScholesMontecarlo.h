#ifndef BlackScholesMonteCarlo_h
#define BlackScholesMonteCarlo_h

#include <cmath>
#include <tuple>

#include "PathDependentOption.h"
#include "PathIndependentOption.h"
#include "SimulationRunner.h"
#include "Volatility.h"


/*!
 * @brief Class for the Black-Scholes model using Monte Carlo methods
 */
class BlackScholesMonteCarlo
{
public:

    /*!
     * @brief Contructor for the BlackScholesMonteCarlo class
     * @details This constructor takes as arguments an optional number of
     * conditions to stop a running simulation. Must have at least one condition
     * passed as arguments
     *
     * @param    vol         the volatility of the underlying asset
     * @param    condition   the first condition to stop a running simulation
     * @param    conditions  the other optional conditions to stop a simulation
     */
    template<typename... StopConditions>
    BlackScholesMonteCarlo(const Volatility& vol,
                           StopSimulation* condition,
                           StopConditions... conditions);

    /*!
     * @brief Contructor for the BlackScholesMonteCarlo class
     * @details This constructor takes as arguments a std::vector of conditions
     * to stop a running simulation.
     *
     * @param    vol         the volatility of the underlying asset
     * @param    conditions  the conditions to stop a simulation. Cannot be empty
     */
    BlackScholesMonteCarlo(const Volatility& vol,
                           std::vector<StopSimulation*>& conditions);

    virtual ~BlackScholesMonteCarlo();

    /*!
     * @brief Returns the price of a path-independent option with the delta and
     * the gamma
     *
     * @param    r       the riskless rate
     * @param    s0      the initial spot
     * @param    option  the option to price
     * @return the price, the delta, the gamma
     */
    std::tuple<double, double, double> hedge(double r,
                                             double s0,
                                             const PathIndependentOption& option) const;

    /*!
     * @brief Returns the price of a path-independent option
     *
     * @param    r       the riskless rate
     * @param    s0      the initial spot
     * @param    option  the option to price
     * @return the price
     */
    double price(double r, double s0, const PathIndependentOption& option) const;

    /*!
     * @brief Returns the price of a path-dependent option
     *
     * @param    r       the riskless rate
     * @param    s0      the initial spot
     * @param    option  the option to price
     * @return the price
     */
    double price(double r, double s0, const PathDependentOption& option) const;

    /*!
     * @brief Prints the model in the output stream
     *
     * @param    os  the ouput stream
     */
    void print(std::ostream& os) const;

private:

    /*!
     * @brief Computes the price of an option by running a Monte Carlo simulation
     *
     * @tparam  Gen     the type of generator: stock prices or stock path prices
     * @tparam  Opt     the option class
     *
     * @param   gen     the generator of stock (path) prices
     * @param   option  the option to price
     * @param   r       the riskless rate
     * @param   s0      the initial spot
     * @return the price
     */
    template <class Gen, class Opt>
    double runSimulation(Gen& gen, const Opt& option, double r, double s0) const;

private:
    Volatility _vol;
    SimulationRunner _simRunner;
};

/*!
 * @brief Overloads the << operator for the BlackScholesMonteCarlo class
 *
 * @param   os              the ouput stream
 * @param   bs_montecarlo   the model to print in os
 */
std::ostream& operator<<(std::ostream& os, const BlackScholesMonteCarlo& bs_montecarlo);


template<typename... StopConditions>
BlackScholesMonteCarlo::BlackScholesMonteCarlo(const Volatility& vol,
                                               StopSimulation* condition,
                                               StopConditions... conditions)
    : _vol(vol)
    , _simRunner(condition, conditions...)
{
}

template <class Gen, class Opt>
double BlackScholesMonteCarlo::runSimulation(Gen& gen,
                                             const Opt& option,
                                             double r,
                                             double s0) const
{
    auto payoff = [&gen, &option, s0]() { return option.payoff(gen(s0)); };
    const double T = static_cast<double>(option.maturity()) / _vol.period();
    return exp(-r * T) * _simRunner.run(payoff).mean();
}


#endif // BlackScholesMonteCarlo_h
