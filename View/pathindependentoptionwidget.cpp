#include "pathindependentoptionwidget.h"

PathIndependentOptionWidget::PathIndependentOptionWidget(QWidget* parent)
    : BaseOptionWidget(parent)
    , _strike(new QDoubleSpinBox)
{
    _strike->setRange(0.0, 500.0);
    _strike->setValue(51.0);
    _layout->addRow("Strike", _strike);
}

double PathIndependentOptionWidget::getStrike() const
{
    return _strike->value();
}
