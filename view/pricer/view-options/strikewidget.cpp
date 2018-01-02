#include "strikewidget.h"


double StrikeWidget::_bufferValue = 51.0;


StrikeWidget::StrikeWidget(QWidget* parent)
    : QWidget(parent)
    , _layout(new QHBoxLayout(this))
    , _strike(new QDoubleSpinBox)
{
    _strike->setRange(0.0, 1000.0);
    _layout->addWidget(_strike);
    connect(_strike, SIGNAL(valueChanged(double)), this, SLOT(updateBufferValue(double)));
}

double StrikeWidget::strike() const
{
    return _strike->value();
}

void StrikeWidget::showEvent(QShowEvent* event)
{
    _strike->setValue(_bufferValue);
}

void StrikeWidget::updateBufferValue(double value)
{
    _bufferValue = value;
}
