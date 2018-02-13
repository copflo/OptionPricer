#include "BlackScholesWidget.h"


BlackScholesWidget::BlackScholesWidget(QWidget* parent)
    : QWidget(parent)
    , _layout(new QFormLayout(this))
    , _volatility(new VolatilityWidget)
{
    _layout->addRow("Volatity", _volatility);
}

BlackScholesWidget::~BlackScholesWidget()
{
}

Volatility BlackScholesWidget::volatility() const
{
    return _volatility->volatility();
}
