#include "options/LookbackOption.h"

#include "LookbackOptionFactory.h"


LookbackOptionFactory::LookbackOptionFactory(QWidget* parent)
    : PathDependentOptionWidget(parent)
    , _strike(new OptionalStrikeWidget)
{
    _layout->addRow("Strike", _strike);
}

LookbackOptionFactory::~LookbackOptionFactory()
{
}

ILookbackOption* LookbackOptionFactory::buildOption() const
{
    if (_strike->isFloating()) {
        return new LookbackOption<FloatingStrike>(optionNature(), maturity(), observationFrequency());
    }

    return new LookbackOption<FixedStrike>(optionNature(), maturity(), observationFrequency(), _strike->getStrike());
}
