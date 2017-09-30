#include "CashOrNothingOptionFactory.h"


CashOrNothingOptionFactory::CashOrNothingOptionFactory(QWidget* parent)
    : PathIndependentOptionWidget(parent)
    , _rebate(new QDoubleSpinBox)
{
    _rebate->setMinimum(0.0);
    _rebate->setValue(20.);
    _layout->addRow("Rebate", _rebate);
}

CashOrNothingOptionFactory::~CashOrNothingOptionFactory()
{
}

CashOrNothingOption* CashOrNothingOptionFactory::buildOption() const
{
    return new CashOrNothingOption(optionNature(), maturity(), getStrike(), _rebate->value());
}
