#ifndef LookbackOptionWidget_h
#define LookbackOptionWidget_h

#include "optionalstrikewidget.h"
#include "pathdependentoptionwidget.h"


class LookbackOptionWidget
    : public PathDependentOptionWidget
{
public:
            LookbackOptionWidget(QWidget* parent = nullptr);
    virtual ~LookbackOptionWidget();

    bool strikeIsFloating() const;
    double strike() const;

private:
    OptionalStrikeWidget* _strike;
};


#endif // LookbackOptionWidget_h
