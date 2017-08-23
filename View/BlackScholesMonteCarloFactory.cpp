#include <QFormLayout>

#include "../Models/NbObs.h"
#include "../Models/TimeLimit.h"

#include "BlackScholesMonteCarloFactory.h"

BlackScholesMonteCarloFactory::BlackScholesMonteCarloFactory(QWidget* parent)
    : QWidget(parent)
    , _volatility(new VolatilityWidget)
    , _nbObs(new QCheckBox("Number of observations"))
    , _numberOfObs(new QSpinBox)
    , _timeLimit(new QCheckBox("Time of computation (s)"))
    , _calculusTime(new QDoubleSpinBox)
{
    QFormLayout* layout = new QFormLayout(this);
    layout->addRow("Volatility", _volatility);

    _numberOfObs->setRange(50000, 2000000);
    _numberOfObs->setValue(500000);
    _numberOfObs->setSingleStep(100000);
    layout->addRow(_nbObs, _numberOfObs);

    _calculusTime->setRange(0.3, 60.);
    _calculusTime->setValue(1.);
    layout->addRow(_timeLimit, _calculusTime);
}

BlackScholesMonteCarloFactory::~BlackScholesMonteCarloFactory()
{
}

BlackScholesMonteCarlo* BlackScholesMonteCarloFactory::buildModel() const
{
    std::vector<StopSimulation*> stopConditions;

    if (_nbObs->isChecked()) {
        stopConditions.push_back(new NbObs(_numberOfObs->value()));
    }

    if (_timeLimit->isChecked()) {
        stopConditions.push_back(new TimeLimit(_calculusTime->value()));
    }

    return new BlackScholesMonteCarlo(_volatility->volatility(), stopConditions);
}