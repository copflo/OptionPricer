#include "AmericanOptionFactory.h"

AmericanOptionFactory::AmericanOptionFactory(QWidget* parent)
    : PathIndependentOptionWidget(parent)
{
}

AmericanOptionFactory::~AmericanOptionFactory()
{
}

AmericanOption* AmericanOptionFactory::buildOption() const
{
    return new AmericanOption(optionNature(), maturity(), getStrike());
}