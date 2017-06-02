#include "strikewidget.h"

StrikeWidget::StrikeWidget(QWidget* parent)
    : QWidget(parent)
    , _strike(new QDoubleSpinBox)
{
    _strike->setRange(0.0, 1000.0);
    _strike->setValue(51.0);
}
