#include <QFormLayout>
#include <QLabel>

#include "CoxRossRubinsteinFactory.h"


CoxRossRubinsteinFactory::CoxRossRubinsteinFactory(QWidget* parent)
    : QWidget(parent)
    , _nbSteps(new QSpinBox)
    , _increase(new QDoubleSpinBox)
    , _decrease(new QDoubleSpinBox)
{
    QFormLayout* form = new QFormLayout(this);

    _nbSteps->setValue(3);
    form->addRow("Number of steps", _nbSteps);
    form->addRow("Increase", buildParameterLayout(_increase));
    form->addRow("Decrease", buildParameterLayout(_decrease));
}

CoxRossRubinsteinFactory::~CoxRossRubinsteinFactory()
{
}

CoxRossRubinstein* CoxRossRubinsteinFactory::buildModel() const
{
    return new CoxRossRubinstein(_increase->value() / 100., _decrease->value() / 100., _nbSteps->value());
}

QLayout* CoxRossRubinsteinFactory::buildParameterLayout(QDoubleSpinBox* widget)
{
    QBoxLayout* layout = new QHBoxLayout;
    widget->setRange(0.0, 120.);
    widget->setValue(10.);
    layout->addWidget(widget);
    layout->addWidget(new QLabel("%"));
    return layout;
}
