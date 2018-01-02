#include "pathindependentoptionwidget.h"


PathIndependentOptionWidget::PathIndependentOptionWidget(QWidget* parent)
    : BaseOptionWidget(parent)
    , _strike(new StrikeWidget)
{
    _layout->addRow("Strike", _strike);
}

double PathIndependentOptionWidget::getStrike() const
{
    return _strike->strike();
}
