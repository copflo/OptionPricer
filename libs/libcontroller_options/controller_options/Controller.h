#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>

#include "AController.h"


template<class MktUI, class OptFactUI, class ModlFactUI>
class Controller
    : public AController
{
public:
    Controller(MktUI& mktUI, OptFactUI& optFactUI, ModlFactUI& modlFactUI);

    double computePrice() const;
    void setAvailableModels(const std::string& optionType);

protected:
    MktUI& _mktUI;
    OptFactUI& _optFactUI;
    ModlFactUI& _modlFactUI;
};


template<class MktUI, class OptFactUI, class ModlFactUI>
Controller<MktUI, OptFactUI, ModlFactUI>::Controller(MktUI& mktUI,
                                                     OptFactUI& optFactUI,
                                                     ModlFactUI& modlFactUI)
    : AController(buildPricingMap(mktUI, optFactUI, modlFactUI))
    , _mktUI(mktUI)
    , _optFactUI(optFactUI)
    , _modlFactUI(modlFactUI)
{
}

template<class OptFactUI, class ModlFactUI, class MktUI>
double Controller<OptFactUI, ModlFactUI, MktUI>::computePrice() const
{
    const std::string optionChoice = _optFactUI.choice();
    const std::string modelChoice = _modlFactUI.choice();
    return _pricingMap.at({optionChoice, modelChoice})();
}

template<class OptFactUI, class ModlFactUI, class MktUI>
void Controller<OptFactUI, ModlFactUI, MktUI>::setAvailableModels(const std::string& optionType)
{
    _modlFactUI.setAvailableModels(availableModels().at(optionType));
}


#endif // CONTROLLER_H
