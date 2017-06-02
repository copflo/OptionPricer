#ifndef PATHINDEPENDENTOPTIONWIDGET_H
#define PATHINDEPENDENTOPTIONWIDGET_H

#include <QDoubleSpinBox>

#include "BaseOptionWidget.h"

class PathIndependentOptionWidget
    : public BaseOptionWidget
{
public:
    PathIndependentOptionWidget(QWidget* parent = nullptr);

    double getStrike() const;

private:
    QDoubleSpinBox* _strike;
};

#endif // PATHINDEPENDENTOPTIONWIDGET_H
