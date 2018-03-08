#include "NbObs.h"


NbObs::NbObs(size_t nbObs)
    : _nbObs(nbObs)
{
}

NbObs::~NbObs()
{
}

bool NbObs::stop(const MC_Simulation& stats) const
{
    return stats.nbObservations() >= _nbObs;
}
