#ifndef PATHDEPENDENTOPTIONWIDGET_H
#define PATHDEPENDENTOPTIONWIDGET_H

#include "BaseOptionWidget.h"


class PathDependentOptionWidget
    : public BaseOptionWidget
{
public:
    PathDependentOptionWidget(QWidget* parent = nullptr);

    int observationFrequency() const;

private:
    QLayout* buildObsFrequency();

private:
    QSpinBox* _obsFrequency;
};


#endif // PATHDEPENDENTOPTIONWIDGET_H
