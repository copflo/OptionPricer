#ifndef DigitalOption_h
#define DigitalOption_h

#include "PathIndependentOption.h"


class DigitalOption
    : public PathIndependentOption
{
public:
            DigitalOption (OptionNature* nature, int maturity, double strike);
    virtual ~DigitalOption();

    bool successfulBet(double spot) const;
};


#endif // DigitalOption_h
