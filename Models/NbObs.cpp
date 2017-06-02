#include "NbObs.h"

NbObs::NbObs(size_t nbObs)
    : _nbObs(nbObs)
{
}

NbObs::~NbObs()
{
}

bool NbObs::stop(const RunningSimulation& simulation) const
{
    return simulation.nbObservations() >= _nbObs;
}
