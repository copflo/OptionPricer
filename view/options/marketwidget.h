#ifndef MARKETWIDGET_H
#define MARKETWIDGET_H

#include <QDoubleSpinBox>


class MarketWidget
    : public QWidget
{
public:
    MarketWidget(QWidget* parent = nullptr);

    double riskfreeRate() const;
    double currentSpot () const;

private:
    QLayout* buildRiskfreeRate();
    QWidget* buildCurrentSpot();

private:
    QDoubleSpinBox* _riskfreeRate;
    QDoubleSpinBox* _currentSpot;
};


#endif // MARKETWIDGET_H
