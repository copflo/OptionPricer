#ifndef OPTIONWIDGET_H
#define OPTIONWIDGET_H

#include <QFormLayout>
#include <QRadioButton>
#include <QSpinBox>

#include "options/Option.h"


class BaseOptionWidget
    : public QWidget
{
public:
    BaseOptionWidget(QWidget* parent = nullptr);

    Option::Nature optionNature() const;
    int            maturity    () const;

private:
    QWidget* buildOptionNatureWidget();
    QLayout* buildMaturityWidget();

protected:
    QFormLayout* _layout;

private:
    QRadioButton* _call;
    QRadioButton* _put;
    QSpinBox*     _maturity;
};


#endif // OPTIONWIDGET_H
