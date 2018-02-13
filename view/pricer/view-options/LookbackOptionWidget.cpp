#include "LookbackOptionWidget.h"


LookbackOptionWidget::LookbackOptionWidget(QWidget* parent)
    : PathDependentOptionWidget(parent)
    , _strike(new OptionalStrikeWidget)
{
    _layout->addRow("Strike", _strike);
}

LookbackOptionWidget::~LookbackOptionWidget()
{
}

bool LookbackOptionWidget::strikeIsFloating() const
{
    return _strike->isFloating();
}

double LookbackOptionWidget::strike() const
{
    return _strike->strike();
}
