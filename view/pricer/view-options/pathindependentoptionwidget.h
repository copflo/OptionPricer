#ifndef PATHINDEPENDENTOPTIONWIDGET_H
#define PATHINDEPENDENTOPTIONWIDGET_H

#include "BaseOptionWidget.h"
#include "strikewidget.h"


class PathIndependentOptionWidget
    : public BaseOptionWidget
{
public:
    PathIndependentOptionWidget(QWidget* parent = nullptr);

    double strike() const;

private:
    StrikeWidget* _strike;
};


#endif // PATHINDEPENDENTOPTIONWIDGET_H
