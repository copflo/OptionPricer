#ifndef VOLATILITYWIDGET_H
#define VOLATILITYWIDGET_H

#include <QCheckBox>
#include <QComboBox>
#include <QDateEdit>
#include <QDoubleSpinBox>
#include <QSpinBox>

#include "options/Volatility.h"


class VolatilityWidget
    : public QWidget
{
    Q_OBJECT

private:
    static double bufferValue;
    static int    bufferPeriod;

public:
    explicit VolatilityWidget(QWidget* parent = nullptr);

    Volatility volatility() const;

protected:
    virtual void showEvent(QShowEvent* event);

private slots:
    void updateBufferValue (double val);
    void updateBufferPeriod(int period);

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
