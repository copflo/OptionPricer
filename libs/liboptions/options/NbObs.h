#ifndef NbObs_h
#define NbObs_h

#include "StopSimulation.h"


/*!
 * @brief Class for checking if a Monte Carlo simulation should be stopped for
 * having reached a threshold number of observations
 */
class NbObs
    : public StopSimulation
{
public:

    /*!
     * @brief Contructor for the NbObs class
     *
     * @param   nbObs   the maximum number of observations there should be in
     *                  a simulation
     */
    NbObs(size_t nbObs);

    virtual ~NbObs();

    /*!
     * @brief Checks if the simulation should be stopped
     *
     * @param   sim the running simulation
     * @return true if the current number of observations has reached the
     * threshold level, false otherwise
     */
    virtual bool stop(const MC_Simulation& sim) const;

private:
    const size_t _nbObs;
};


#endif //NbObs_h
