#include <QHBoxLayout>

#include "maturitywidget.h"


int MaturityWidget::_bufferValue = 90;


MaturityWidget::MaturityWidget(QWidget *parent)
    : QWidget(parent)
    , _maturity(new QSpinBox)
    , _day(new QLabel)
{
    QBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(_maturity);
    layout->addWidget(_day);
    _maturity->setRange(1, 1000);

    connect(_maturity, SIGNAL(valueChanged(int)), this, SLOT(updateBuffer(int)));
    connect(_maturity, SIGNAL(valueChanged(int)), this, SLOT(setPlural(int)));
}

size_t MaturityWidget::maturity() const
{
    return static_cast<size_t>(_maturity->value());
}

void MaturityWidget::showEvent(QShowEvent *event)
{
    _maturity->setValue(_bufferValue);
}

void MaturityWidget::updateBuffer(int value)
{
    _bufferValue = value;
}

void MaturityWidget::setPlural(int value)
{
    if(value > 1) {
        if(!_day->text().endsWith('s')) {
            _day->setText("days");
        }
    }
    else {
        _day->setText("day");
    }
}
