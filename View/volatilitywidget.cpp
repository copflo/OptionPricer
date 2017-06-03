#include <QHBoxLayout>
#include <QLabel>
#include "volatilitywidget.h"

VolatilityWidget::VolatilityWidget(QWidget* parent)
    : QWidget(parent)
    , _value(new QDoubleSpinBox)
    , _period(new QSpinBox)
{
    QBoxLayout* layout = new QHBoxLayout(this);
    layout->addLayout(buildValue());
    layout->addWidget(new QLabel("on"));
    layout->addLayout(buildPeriod());
}

Volatility VolatilityWidget::getVolatility() const
{
    return Volatility(_value->value() / 100., _period->value());
}

QLayout* VolatilityWidget::buildValue()
{
    _value->setRange(0.0, 150);
    _value->setValue(30.0);
    QBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(_value);
    layout->addWidget(new QLabel("%"));

    return layout;
}

QLayout* VolatilityWidget::buildPeriod()
{
    _period->setRange(1, 1000);
    _period->setValue(252);
    QBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(_period);
    layout->addWidget(new QLabel("day(s)"));

    return layout;
}