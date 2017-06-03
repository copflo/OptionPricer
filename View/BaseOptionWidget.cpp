#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>

#include "BaseOptionWidget.h"

BaseOptionWidget::BaseOptionWidget(QWidget *parent)
    : QWidget(parent)
    , _layout  (new QFormLayout(this))
    , _call    (new QRadioButton("Call"))
    , _put     (new QRadioButton("Put"))
    , _maturity(new QSpinBox)
{
    _layout->addRow(buildOptionNatureWidget());
    _layout->addRow("Maturity", buildMaturityWidget());
}

Option::Nature BaseOptionWidget::optionNature() const
{
    if(_call->isChecked()) {
        return Option::CALL;
    }

    return Option::PUT;
}

int BaseOptionWidget::maturity() const
{
    return _maturity->value();
}

QWidget* BaseOptionWidget::buildOptionNatureWidget()
{
    QGroupBox* nature = new QGroupBox("Nature");

    QBoxLayout* natureLayout = new QHBoxLayout(nature);

    _call->setChecked(true);
    natureLayout->addWidget(_call);

    natureLayout->addWidget(_put);

    nature->setLayout(natureLayout);

    return nature;
}

QLayout* BaseOptionWidget::buildMaturityWidget()
{
    _maturity->setRange(1, 1000);
    _maturity->setValue(90);

    QBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(_maturity);
    layout->addWidget(new QLabel("day(s)"));
    return layout;
}