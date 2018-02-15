#ifndef BLACKSCHOLESMCFACTORY_H
#define BLACKSCHOLESMCFACTORY_H

#include "options/BlackScholesMonteCarlo.h"

#include "Factory.h"


template<>
template<class UI>
BlackScholesMonteCarlo* Factory<BlackScholesMonteCarlo>::build(const UI& ui)
{
    std::vector<StopSimulation*> stopCdts;
    if(ui.nbObsCondition()) {
        stopCdts.push_back(new NbObs(ui.nbObs()));
    }
    if(ui.timeLimitCondition()) {
        stopCdts.push_back(new TimeLimit(ui.timeLimit()));
    }
    return new BlackScholesMonteCarlo(ui.volatility(), stopCdts);
}


#endif // BLACKSCHOLESMCFACTORY_H
