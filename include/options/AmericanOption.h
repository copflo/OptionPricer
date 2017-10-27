#ifndef AmericanOption_h
#define AmericanOption_h

#include "VanillaOption.h"


class AmericanOption
    : public VanillaOption
{
public:
            AmericanOption (OptionNature* nature, int maturity, double strike);
    virtual ~AmericanOption();

    virtual std::string style() const;
};


#endif // AmericanOption_h
