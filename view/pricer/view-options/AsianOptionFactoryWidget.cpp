#include <QGroupBox>

#include "AsianOptionWidget.h"


AsianOptionWidget::AsianOptionWidget(QWidget* parent)
    : PathDependentOptionWidget(parent)
    , _strike(new OptionalStrikeWidget)
    , _arithmetic(new QRadioButton("Arithmetic"))
    , _geometric(new QRadioButton("Geometric"))
{
    _layout->addRow("Strike", _strike);

    QGroupBox* average = new QGroupBox;
    QBoxLayout* averageLayout = new QHBoxLayout;

    _arithmetic->setChecked(true);
    averageLayout->addWidget(_arithmetic);

    averageLayout->addWidget(_geometric);
    average->setLayout(averageLayout);
    _layout->addRow("Average style", average);
}

AsianOptionWidget::~AsianOptionWidget()
{
}

double AsianOptionWidget::strike() const
{
	return _strike->strike();
}

bool AsianOptionWidget::strikeIsFloating() const
{
    return _strike->isFloating();
}

bool AsianOptionWidget::optionIsArithmetic() const
{
    return _arithmetic->isChecked();
}
