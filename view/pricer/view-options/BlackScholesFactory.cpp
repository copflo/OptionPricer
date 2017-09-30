#include <QFormLayout>

#include "BlackScholesFactory.h"


BlackScholesFactory::BlackScholesFactory(QWidget* parent)
    : QWidget(parent)
    , _volatility(new VolatilityWidget)
{
    QFormLayout* layout = new QFormLayout(this);
    layout->addRow("Volatity", _volatility);
}

BlackScholesFactory::~BlackScholesFactory()
{
}

BlackScholes* BlackScholesFactory::buildModel() const
{
    return new BlackScholes(_volatility->volatility());
}

