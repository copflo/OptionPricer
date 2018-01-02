#include <QHBoxLayout>

#include "optionalstrikewidget.h"


OptionalStrikeWidget::OptionalStrikeWidget(QWidget* parent)
    : StrikeWidget(parent)
    , _floating(new QCheckBox("floating"))
{
    _layout->addWidget(_floating);
    connect(_floating, SIGNAL(toggled(bool)), _strike, SLOT(setDisabled(bool)));
}

bool OptionalStrikeWidget::isFloating() const
{
    return _floating->isChecked();
}

double OptionalStrikeWidget::strike() const
{
    if(_floating->isChecked()) {
        return -1.0;
    }

    return _strike->value();
}
