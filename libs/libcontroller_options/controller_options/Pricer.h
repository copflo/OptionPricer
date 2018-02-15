#ifndef PRICER_H
#define PRICER_H

#include <memory>

#include "AsianOptionFactory.hpp"
#include "BarrierOptionFactory.hpp"
#include "CashOrNothingOptionFactory.hpp"
#include "LookbackOptionFactory.hpp"
#include "PathIndependentOptionFactory.hpp"

#include "BinomialTreeFactory.hpp"
#include "BlackScholesFactory.hpp"
#include "BlackScholesMCFactory.hpp"


template<class Opt, class Model>
struct Pricer
{
    template<class MktUI, class OptUI, class ModlUI>
    static double price(const MktUI& mktUI, const OptUI& optUI, const ModlUI& modlUI);
};


template<class Opt, class Model>
template<class MktUI, class OptUI, class ModlUI>
double Pricer<Opt, Model>::price(const MktUI& mktUI, const OptUI& optUI, const ModlUI& modlUI)
{
    std::unique_ptr<Opt> option(Factory<Opt>::build(optUI));
    std::unique_ptr<Model> model(Factory<Model>::build(modlUI));
    return model->price(mktUI.riskfreeRate(), mktUI.spot(), *option);
}


#endif // PRICER_H