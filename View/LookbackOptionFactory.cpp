#include "../Options/FixedStrikeLookbackOption.h"
#include "../Options/FloatingStrikeLookbackOption.h"
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

LookbackOption* LookbackOptionFactory::buildOption() const
{
    if (_strike->isFloating()) {
        return new FloatingStrikeLookbackOption(optionNature(), maturity(), observationFrequency());
    }

    return new FixedStrikeLookbackOption(optionNature(), maturity(), observationFrequency(), _strike->getStrike());
}
