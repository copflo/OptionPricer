#include "EuropeanOptionFactory.h"


EuropeanOptionFactory::EuropeanOptionFactory(QWidget* parent)
    : PathIndependentOptionWidget(parent)
{
}

EuropeanOptionFactory::~EuropeanOptionFactory()
{
}

EuropeanOption* EuropeanOptionFactory::buildOption() const
{
    return new EuropeanOption(optionNature(), maturity(), getStrike());
}
