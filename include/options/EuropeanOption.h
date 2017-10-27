#ifndef EuropeanOption_h
#define EuropeanOption_h

#include "VanillaOption.h"


class EuropeanOption
    : public VanillaOption
{
public:
            EuropeanOption(OptionNature* nature, int maturity, double strike);
    virtual ~EuropeanOption();

    virtual std::string style() const;
};


#endif // EuropeanOption_h
