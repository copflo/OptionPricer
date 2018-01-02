#ifndef OPTIONWIDGET_H
#define OPTIONWIDGET_H

#include <QFormLayout>

#include "options/OptionNature.h"

#include "maturitywidget.h"
#include "optionnaturewidget.h"


class BaseOptionWidget
    : public QWidget
{
public:
    BaseOptionWidget(QWidget* parent = nullptr);

    OptionNature* optionNature() const;
    size_t        maturity    () const;

protected:
    QFormLayout* _layout;

private:
    OptionNatureWidget* _nature;
    MaturityWidget*     _maturity;
};


#endif // OPTIONWIDGET_H
