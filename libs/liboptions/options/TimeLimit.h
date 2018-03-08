#ifndef TimeLimit_h
#define TimeLimit_h

#include "StopSimulation.h"


/*!
 * @brief Class for checking if a Monte Carlo simulation should be stopped for
 * having reached a threshold duration
 */
class TimeLimit 
    : public StopSimulation
{
public:

    /*!
     * @brief Contructor for the TimeLimit class
     *
     * @param   calculusTime    the threshold time of computation in a simulation
     */
    TimeLimit(double calculusTime);

    virtual ~TimeLimit();

    /*!
     * @brief Checks if the simulation should be stopped
     *
     * @param   sim the running simulation
     * @return true if the time of computation has reached the threshold level, 
     * false otherwise
     */
    virtual bool stop(const MC_Simulation& sim) const;

private:
    const seconds _calculusTime;
};


#endif // TimeLimit_h
