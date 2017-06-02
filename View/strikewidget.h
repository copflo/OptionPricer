#ifndef STRIKEWIDGET_H
#define STRIKEWIDGET_H

#include <QDoubleSpinBox>

class StrikeWidget
    : public QWidget
{
public:
    StrikeWidget(QWidget *parent = 0);

    virtual double getStrike() const = 0;

protected:
    QDoubleSpinBox* _strike;
};

#endif // STRIKEWIDGET_H
