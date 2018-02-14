#ifndef LookbackOption_h
#define LookbackOption_h

#include "FixedStrike.h"
#include "FloatingStrike.h"
#include "ILookbackOption.h"


template<class StrikeFloatingness>
class LookbackOption;


template<>
class LookbackOption<FixedStrike>
    : public ILookbackOption
    , public FixedStrike
{
public:
            LookbackOption (OptionNature* nature, size_t maturity, size_t obsFreq, double strike);
    virtual ~LookbackOption();

    virtual double payoff(const std::vector<double>& spot_path) const;
    virtual void   print(std::ostream& os)                      const;

private:
    double optimalSpot(const std::vector<double>& spot_path) const;
};


template<>
class LookbackOption<FloatingStrike>
    : public ILookbackOption
    , public FloatingStrike
{
public:
            LookbackOption(OptionNature* nature, size_t maturity, size_t obsFreq);
    virtual ~LookbackOption();

    virtual double payoff(const std::vector<double>& spot_path) const;
    virtual double strike(const std::vector<double>& spot_path) const;
    virtual void   print (std::ostream& os)                     const;
};


#endif // LookbackOption_h