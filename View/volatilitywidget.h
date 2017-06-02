#ifndef VOLATILITYWIDGET_H
#define VOLATILITYWIDGET_H

#include <QDoubleSpinBox>
#include <QSpinBox>

#include "../Models/Volatility.h"

class VolatilityWidget
    : public QWidget
{
public:
    explicit VolatilityWidget(QWidget* parent = nullptr);

    Volatility getVolatility() const;

private:
    QLayout* buildValue();
    QLayout* buildPeriod();

private:
    QDoubleSpinBox* _value;
    QSpinBox*       _period;
};

#endif // VOLATILITYWIDGET_H
