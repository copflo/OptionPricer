#ifndef FloatingStrikeLookbackOption_h
#define FloatingStrikeLookbackOption_h

#include "FloatingStrike.h"
#include "LookbackOption.h"

class FloatingStrikeLookbackOption 
    : public LookbackOption
    , public FloatingStrike
{
public:
            FloatingStrikeLookbackOption (Nature nature, int maturity, int obsFreq);
    virtual ~FloatingStrikeLookbackOption();

    virtual double payoff(const std::vector<double>& spot_path) const;
    virtual double strike(const std::vector<double>& spot_path) const;
    virtual void print(std::ostream& os) const;
};

#endif /* FloatingStrikeLookbackOption_h */