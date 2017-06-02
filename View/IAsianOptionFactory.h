#ifndef IAsianOptionFactory_h
#define IAsianOptionFactory_h

#include "../Options/AsianOption.h"

#include "optionalstrikewidget.h"
#include "pathdependentoptionwidget.h"

class IAsianOptionFactory 
    : public PathDependentOptionWidget
{
public:
            IAsianOptionFactory (QWidget* parent = nullptr);
    virtual ~IAsianOptionFactory();

    IAsianOption* buildOption() const;

private:
    OptionalStrikeWidget* _strike;
    QRadioButton* _arithmetic;
    QRadioButton* _geometric;
}; 

#endif /* IAsianOptionFactory_h */