#ifndef VOLATILITYWIDGET_H
#define VOLATILITYWIDGET_H

#include <QCheckBox>
#include <QComboBox>
#include <QDateEdit>
#include <QDoubleSpinBox>
#include <QSpinBox>

#include "../Models/Volatility.h"

class VolatilityWidget
    : public QWidget
{
    Q_OBJECT
        
public:
    explicit VolatilityWidget(QWidget* parent = nullptr);

    Volatility getVolatility() const;

private:
    QLayout* buildFirstLine   ();
    QLayout* buildDateBoundary(QString&& boundaryType, QDateEdit* dateEdit, QDate&& date);

private:
    QDoubleSpinBox* _value;
    QSpinBox*       _period;
    QComboBox*      _type;
    QDateEdit*      _from;
    QDateEdit*      _to;
};

#endif // VOLATILITYWIDGET_H
