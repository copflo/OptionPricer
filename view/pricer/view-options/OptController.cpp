#include <QMessageBox>

#include "OptController.h"


OptController::OptController(MarketWidget& mktWdgt,
                             OptionFactoryWidget& optFactWdgt,
                             ModelFactoryWidget& modlFactWdgt)
    : Controller<MarketWidget, OptionFactoryWidget, ModelFactoryWidget, QString>(mktWdgt, optFactWdgt, modlFactWdgt)
{
    connect(&_optFactUI, SIGNAL(currentStyleChanged(const QString&)), 
            this,    	 SLOT(setAvailableModels(const QString&)));
    setAvailableModels(_optFactUI.choice());
}

OptController::~OptController()
{
}

void OptController::priceOption()
{
    try {
        const double p = computePrice();
        emit(optionPriced(p));
    }
    catch (const std::exception& ex) {
        QMessageBox::critical(nullptr, "Error", ex.what());
    }
}

void OptController::setAvailableModels(const QString& optionType)
{
    Controller<MarketWidget, OptionFactoryWidget, ModelFactoryWidget, QString>::setAvailableModels(optionType);
}
