#ifndef BLACKSCHOLESFACTORY_H
#define BLACKSCHOLESFACTORY_H

#include "options/BlackScholes.h"

#include "Factory.h"


template<>
template<class UI>
BlackScholes* Factory<BlackScholes>::build(const UI& ui)
{
    return new BlackScholes(ui.volatility());
}


#endif // BLACKSCHOLESFACTORY_H
