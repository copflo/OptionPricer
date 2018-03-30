#ifndef StopSimulation_h
#define StopSimulation_h

#include "MC_Simulation.h"


/*!
 * @brief Base class for conditions checking if a running Monte Carlo simulation should be 
 * stopped
 */
class StopSimulation
{
public:

    /*! 
     * @brief Constructor for the StopSimulation class  
     */
    StopSimulation();

    virtual ~StopSimulation();

    /*!
     * @brief Pure virtual method indicating if the running simulation must be stopped
     * 
     * @param   sim the running simulation
     * @return true if the simulation must be stopped, false otherwise
     */
    virtual bool stop(const MC_Simulation& sim) const = 0;
};


#endif // StopSimulation_h
