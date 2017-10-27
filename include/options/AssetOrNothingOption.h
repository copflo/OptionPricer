#ifndef AssetOrNothingOption_h
#define AssetOrNothingOption_h

#include "DigitalOption.h"


class AssetOrNothingOption
    : public DigitalOption
{
public:
            AssetOrNothingOption (OptionNature* nature, int maturity, double strike);
    virtual ~AssetOrNothingOption();

    virtual std::string style()             const;
    virtual double      payoff(double spot) const;
};


#endif // AssetOrNothingOption_h
