#ifndef FixedStrikeLookbackOption_h
#define FixedStrikeLookbackOption_h

#include "FixedStrike.h"
#include "LookbackOption.h"

class FixedStrikeLookbackOption 
    : public LookbackOption
    , public FixedStrike
{
public:
            FixedStrikeLookbackOption(Nature nature, int maturity, int obsFreq, double strike);
    virtual ~FixedStrikeLookbackOption();

    virtual double payoff(const std::vector<double>& spot_path) const;
    virtual void   print (std::ostream& os)                     const;

private:
    double optimalSpot(const std::vector<double>& spot_path) const;
};

#endif /* FixedStrikeLookbackOption_h */