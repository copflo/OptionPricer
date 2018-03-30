#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ModelsCatalog.h"
#include "PricingMapBuilder.h"


template<class MktUI, class OptFactUI, class ModlFactUI, class Str>
class Controller
{
public:
    Controller(MktUI& mktUI, OptFactUI& optFactUI, ModlFactUI& modlFactUI);

    double computePrice() const;
    void setAvailableModels(const Str& optionType);

protected:
    MktUI& _mktUI;
    OptFactUI& _optFactUI;
    ModlFactUI& _modlFactUI;
    std::map<std::pair<Str, Str>, std::function<double()>> _pricingMap;
};


template<class MktUI, class OptFactUI, class ModlFactUI, class Str>
Controller<MktUI, OptFactUI, ModlFactUI, Str>::Controller(MktUI& mktUI,
                                                          OptFactUI& optFactUI,
                                                          ModlFactUI& modlFactUI)
    : _mktUI(mktUI)
    , _optFactUI(optFactUI)
    , _modlFactUI(modlFactUI)
    , _pricingMap(PricingMapBuilder<Str>::build(mktUI, optFactUI, modlFactUI))
{
}

template<class MktUI, class OptFactUI, class ModlFactUI, class Str>
double Controller<MktUI, OptFactUI, ModlFactUI, Str>::computePrice() const
{
    const Str optionChoice = _optFactUI.choice();
    const Str modelChoice = _modlFactUI.choice();
    return _pricingMap.at({optionChoice, modelChoice})();
}

template<class MktUI, class OptFactUI, class ModlFactUI, class Str>
void Controller<MktUI, OptFactUI, ModlFactUI, Str>::setAvailableModels(const Str& optionType)
{
    _modlFactUI.setAvailableModels(ModelsCatalog<Str>::modelsFor(optionType));
}


#endif // CONTROLLER_H
