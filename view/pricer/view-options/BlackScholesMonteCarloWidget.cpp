#include "BlackScholesMonteCarloWidget.h"


BlackScholesMonteCarloWidget::BlackScholesMonteCarloWidget(QWidget* parent)
    : BlackScholesWidget(parent)
    , _nbObs(new QCheckBox("Number of observations"))
    , _numberOfObs(new QSpinBox)
    , _timeLimit(new QCheckBox("Time of computation (s)"))
    , _calculusTime(new QDoubleSpinBox)
{
    _numberOfObs->setRange(50000, 2000000);
    _numberOfObs->setValue(500000);
    _numberOfObs->setSingleStep(100000);
    _layout->addRow(_nbObs, _numberOfObs);

    _calculusTime->setRange(0.3, 60.);
    _calculusTime->setValue(1.);
    _layout->addRow(_timeLimit, _calculusTime);
}

BlackScholesMonteCarloWidget::~BlackScholesMonteCarloWidget()
{
}

bool BlackScholesMonteCarloWidget::nbObsCondition() const
{
    return _nbObs->isChecked();
}

bool BlackScholesMonteCarloWidget::timeLimitCondition() const
{
	return _timeLimit->isChecked();
}

size_t BlackScholesMonteCarloWidget::nbObs() const
{
    return _numberOfObs->value();
}

double BlackScholesMonteCarloWidget::timeLimit() const
{
    return _calculusTime->value();
}
