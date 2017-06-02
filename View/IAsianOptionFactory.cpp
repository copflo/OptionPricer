#include <QGroupBox>

#include "IAsianOptionFactory.h"

IAsianOptionFactory::IAsianOptionFactory(QWidget* parent)
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

IAsianOptionFactory::~IAsianOptionFactory()
{
}

IAsianOption* IAsianOptionFactory::buildOption() const
{
    if (_arithmetic->isChecked()) {
        if (_strike->isFloating()) {
            return new AsianOption<ArithmeticAverage, FloatingStrike>(optionNature(),
                                                                      maturity(),
                                                                      observationFrequency());
        }

        return new AsianOption<ArithmeticAverage, FixedStrike>(optionNature(),
                                                               maturity(),
                                                               observationFrequency(),
                                                               _strike->getStrike());
    }

    if (_strike->isFloating()) {
        return new AsianOption<GeometricAverage, FloatingStrike>(optionNature(),
                                                                 maturity(),
                                                                 observationFrequency());
    }

    return new AsianOption<GeometricAverage, FixedStrike>(optionNature(),
                                                          maturity(),
                                                          observationFrequency(),
                                                          _strike->getStrike());
}
