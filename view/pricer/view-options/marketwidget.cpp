#include <QFormLayout>
#include <QLabel>

#include "marketwidget.h"


MarketWidget::MarketWidget(QWidget *parent)
    : QWidget(parent)
    , _riskfreeRate(new QDoubleSpinBox)
    , _currentSpot(new QDoubleSpinBox)
{
    QFormLayout* layout = new QFormLayout(this);
    layout->addRow("Risk-free rate", buildRiskfreeRate());
    layout->addRow("Current spot", buildCurrentSpot());
}

double MarketWidget::riskfreeRate() const
{
    return _riskfreeRate->value() / 100.;
}

double MarketWidget::spot() const
{
    return _currentSpot->value();
}

QLayout* MarketWidget::buildRiskfreeRate()
{
    QBoxLayout* layout = new QHBoxLayout;

    _riskfreeRate->setRange(0.0, 100.);
    _riskfreeRate->setValue(6.);
    _riskfreeRate->setSingleStep(0.1);

    layout->addWidget(_riskfreeRate);
    layout->addWidget(new QLabel("%"));

    return layout;
}

QWidget* MarketWidget::buildCurrentSpot()
{
    _currentSpot->setRange(0.0, 1000.0);
    _currentSpot->setValue(50.0);

    return _currentSpot;
}
