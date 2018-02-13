#include "ModelFactory.h"


const std::string& ModelFactory::BINOMIAL_TREE()
{
    static const std::string _binomialtree("Binomial Tree");
    return _binomialtree;
}

const std::string& ModelFactory::BLACK_SCHOLES()
{
    static const std::string _bs("Black Scholes");
    return _bs;
}

const std::string& ModelFactory::BLACK_SCHOLES_MC()
{
    static const std::string _bsMC("Black Scholes - Monte Carlo");
    return _bsMC;
}
