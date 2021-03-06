#ifndef BINOMIALTREEFACTORY_H
#define BINOMIALTREEFACTORY_H

#include "options/BinomialTree.h"

#include "Factory.h"


template<>
template<class UI>
BinomialTree* Factory<BinomialTree>::build(const UI& ui)
{
    return new BinomialTree(ui.up(), ui.down(), ui.nbSteps());
}


#endif // BINOMIALTREEFACTORY_H
