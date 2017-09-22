#ifndef CashOrNothingOptionFactory_h
#define CashOrNothingOptionFactory_h

#include "options/CashOrNothingOption.h"

#include "pathindependentoptionwidget.h"


class CashOrNothingOptionFactory 
    : public PathIndependentOptionWidget
{
public:
            CashOrNothingOptionFactory(QWidget* parent = nullptr);
    virtual ~CashOrNothingOptionFactory();

    CashOrNothingOption* buildOption() const;

private:
    QDoubleSpinBox* _rebate;
};


#endif // CashOrNothingOptionFactory_h
