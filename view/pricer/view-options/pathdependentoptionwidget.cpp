#include <QLabel>

#include "pathdependentoptionwidget.h"


PathDependentOptionWidget::PathDependentOptionWidget(QWidget* parent)
    : BaseOptionWidget(parent)
    , _obsFrequency(new QSpinBox)
{
    _layout->addRow("Observation every", buildObsFrequency());
}

int PathDependentOptionWidget::observationFrequency() const
{
    return _obsFrequency->value();
}

QLayout* PathDependentOptionWidget::buildObsFrequency()
{
    _obsFrequency->setRange(1, 100);
    _obsFrequency->setValue(1);
    QBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(_obsFrequency);
    layout->addWidget(new QLabel("day(s)"));

    return layout;
}
