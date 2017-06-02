#ifndef EuropeanOptionFactory_h
#define EuropeanOptionFactory_h

#include "../Options/EuropeanOption.h"

#include "pathindependentoptionwidget.h"

class EuropeanOptionFactory 
    : public PathIndependentOptionWidget
{
public:
            EuropeanOptionFactory (QWidget* parent = nullptr);
    virtual ~EuropeanOptionFactory();

    EuropeanOption* buildOption() const;
};

#endif /* EuropeanOptionFactory_h */