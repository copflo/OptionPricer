#include <QFormLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "volatilitywidget.h"


double VolatilityWidget::bufferValue = 10.;
int    VolatilityWidget::bufferPeriod = 252;


VolatilityWidget::VolatilityWidget(QWidget* parent)
    : QWidget(parent)
    , _value(new QDoubleSpinBox)
    , _period(new QSpinBox)
    , _type(new QComboBox)
    , _from(new QDateEdit)
    , _to(new QDateEdit)
{
    QGridLayout* layout = new QGridLayout(this);  
    layout->addLayout(buildFirstLine(), 0, 0);
    _type->addItems({ "Standard", "Trading", "Parkinson" });
    layout->addWidget(_type, 1, 0);
    layout->addLayout(buildDateBoundary("From", _from, QDate(2017, 4, 22)), 2, 0);
    layout->addLayout(buildDateBoundary("To", _to, QDate(2017, 6, 22)), 2, 1);

    connect(_value, SIGNAL(valueChanged(double)), this, SLOT(updateBufferValue(double)));
    connect(_period, SIGNAL(valueChanged(int)), this, SLOT(updateBufferPeriod(int)));
}

Volatility VolatilityWidget::volatility() const
{
    return Volatility(_value->value() / 100., _period->value());
}

void VolatilityWidget::showEvent(QShowEvent* event)
{
    _value->setValue(bufferValue);
    _period->setValue(bufferPeriod);
}

void VolatilityWidget::updateBufferValue(double val)
{
    bufferValue = val;
}

void VolatilityWidget::updateBufferPeriod(int period)
{
    bufferPeriod = period;
}

QLayout* VolatilityWidget::buildFirstLine()
{
    QBoxLayout* layout = new QHBoxLayout;

    _value->setRange(0.0, 150);
    layout->addWidget(_value);
    layout->addWidget(new QLabel("%"));

    layout->addWidget(new QPushButton(QIcon("../icons/database.png"), ""));

    layout->addWidget(new QLabel("on"));
    _period->setRange(1, 1000);
    layout->addWidget(_period);
    layout->addWidget(new QLabel("day(s)"));

    return layout;
}

QLayout* VolatilityWidget::buildDateBoundary(QString&& boundaryType, QDateEdit* dateEdit, QDate&& date)
{
    QFormLayout* layout = new QFormLayout;
    QCheckBox* checkBox = new QCheckBox(boundaryType);
    dateEdit->setDate(date);
    dateEdit->setEnabled(false);
    connect(checkBox, SIGNAL(toggled(bool)), dateEdit, SLOT(setEnabled(bool)));
    layout->addRow(checkBox, dateEdit);
    return layout;
}
