#ifndef OPTIONWIDGET_H
#define OPTIONWIDGET_H

#include <QFormLayout>
#include <QRadioButton>
#include <QSpinBox>

#include "options/OptionNature.h"


class BaseOptionWidget
    : public QWidget
{
public:
    BaseOptionWidget(QWidget* parent = nullptr);

    OptionNature* optionNature() const;
    int           maturity    () const;

private:
    QWidget* buildOptionNatureWidget();
    QLayout* buildMaturityWidget();

protected:
    QFormLayout* _layout;

private:
    QRadioButton* _call;
    QSpinBox*     _maturity;
};


#endif // OPTIONWIDGET_H
