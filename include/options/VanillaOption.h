#ifndef VanillaOption_h
#define VanillaOption_h

#include "PathIndependentOption.h"


class VanillaOption
    : public PathIndependentOption
{
public:
            VanillaOption (Nature nature, int maturity, double strike);
    virtual ~VanillaOption();

    virtual double payoff(double spot) const;
};


#endif // VanillaOption_h
