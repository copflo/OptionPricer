#include <QFormLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "volatilitywidget.h"


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
}

Volatility VolatilityWidget::getVolatility() const
{
    return Volatility(_value->value() / 100., _period->value());
}

QLayout* VolatilityWidget::buildFirstLine()
{
    QBoxLayout* layout = new QHBoxLayout;

    _value->setRange(0.0, 150);
    _value->setValue(30.0);
    layout->addWidget(_value);
    layout->addWidget(new QLabel("%"));

    layout->addWidget(new QPushButton(QIcon("icons/database.png"), ""));

    layout->addWidget(new QLabel("on"));
    _period->setRange(1, 1000);
    _period->setValue(252);
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
