#include <QFormLayout>
#include <QLabel>

#include "BinomialTreeFactory.h"


BinomialTreeFactory::BinomialTreeFactory(QWidget* parent)
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

BinomialTreeFactory::~BinomialTreeFactory()
{
}

BinomialTree* BinomialTreeFactory::buildModel() const
{
    return new BinomialTree(_increase->value() / 100., _decrease->value() / 100., _nbSteps->value());
}

QLayout* BinomialTreeFactory::buildParameterLayout(QDoubleSpinBox* widget)
{
    QBoxLayout* layout = new QHBoxLayout;
    widget->setRange(0.0, 120.);
    widget->setValue(10.);
    layout->addWidget(widget);
    layout->addWidget(new QLabel("%"));
    return layout;
}
