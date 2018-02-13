#ifndef AsianOptionWidget_h
#define AsianOptionWidget_h

#include "optionalstrikewidget.h"
#include "pathdependentoptionwidget.h"


class AsianOptionWidget
    : public PathDependentOptionWidget
{
public:
            AsianOptionWidget (QWidget* parent = nullptr);
    virtual ~AsianOptionWidget();

	double strike() const;
    bool strikeIsFloating() const;
    bool optionIsArithmetic() const;

private:
    OptionalStrikeWidget* _strike;
    QRadioButton* _arithmetic;
    QRadioButton* _geometric;
};


#endif // AsianOptionWidget_h
