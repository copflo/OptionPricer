#ifndef LookbackOptionFactory_h
#define LookbackOptionFactory_h

#include "options/ILookbackOption.h"

#include "optionalstrikewidget.h"
#include "pathdependentoptionwidget.h"


class LookbackOptionFactory 
    : public PathDependentOptionWidget
{
public:
            LookbackOptionFactory(QWidget* parent = nullptr);
    virtual ~LookbackOptionFactory();

    ILookbackOption* buildOption() const;

private:
    OptionalStrikeWidget* _strike;
};


#endif // LookbackOptionFactory_h
