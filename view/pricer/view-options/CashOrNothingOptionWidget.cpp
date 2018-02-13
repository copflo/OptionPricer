#include "CashOrNothingOptionWidget.h"


CashOrNothingOptionWidget::CashOrNothingOptionWidget(QWidget* parent)
    : PathIndependentOptionWidget(parent)
    , _rebate(new QDoubleSpinBox)
{
    _rebate->setMinimum(0.0);
    _rebate->setValue(20.);
    _layout->addRow("Rebate", _rebate);
}

CashOrNothingOptionWidget::~CashOrNothingOptionWidget()
{
}

double CashOrNothingOptionWidget::rebate() const
{
    return _rebate->value();
}
