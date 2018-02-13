#include <QFormLayout>
#include <QLabel>

#include "BinomialTreeWidget.h"


QLayout* BinomialTreeWidget::buildParameterLayout(QDoubleSpinBox* widget)
{
    QBoxLayout* layout = new QHBoxLayout;
    widget->setRange(0.0, 120.);
    widget->setValue(10.);
    layout->addWidget(widget);
    layout->addWidget(new QLabel("%"));
    return layout;
}


BinomialTreeWidget::BinomialTreeWidget(QWidget* parent)
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

BinomialTreeWidget::~BinomialTreeWidget()
{
}

double BinomialTreeWidget::up() const
{
    return _increase->value() / 100.;
}

double BinomialTreeWidget::down() const
{
    return _decrease->value() / 100.;
}

size_t BinomialTreeWidget::nbSteps() const
{
    return _nbSteps->value();
 }
