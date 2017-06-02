#ifndef LookbackOptionFactory_h
#define LookbackOptionFactory_h

#include "../Options/LookbackOption.h"

#include "optionalstrikewidget.h"
#include "pathdependentoptionwidget.h"

class LookbackOptionFactory 
    : public PathDependentOptionWidget
{
public:
            LookbackOptionFactory(QWidget* parent = nullptr);
    virtual ~LookbackOptionFactory();

    LookbackOption* buildOption() const;

private:
    OptionalStrikeWidget* _strike;
};

#endif /* LookbackOptionFactory_h */
