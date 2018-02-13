#ifndef CashOrNothingOptionWidget_h
#define CashOrNothingOptionWidget_h

#include "pathindependentoptionwidget.h"


class CashOrNothingOptionWidget
    : public PathIndependentOptionWidget
{
public:
            CashOrNothingOptionWidget(QWidget* parent = nullptr);
    virtual ~CashOrNothingOptionWidget();

    double rebate() const;

private:
    QDoubleSpinBox* _rebate;
};


#endif // CashOrNothingOptionWidget_h
