#ifndef AmericanOptionFactory_h
#define AmericanOptionFactory_h

#include "options/AmericanOption.h"

#include "pathindependentoptionwidget.h"


class AmericanOptionFactory
    : public PathIndependentOptionWidget
{
public:
            AmericanOptionFactory (QWidget* parent = nullptr);
    virtual ~AmericanOptionFactory();

    AmericanOption* buildOption() const;
};


#endif // AmericanOptionFactory_h
