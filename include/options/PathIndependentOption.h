#ifndef PathIndependentOption_h
#define PathIndependentOption_h

#include "FixedStrike.h"
#include "Option.h"


class PathIndependentOption
    : public Option
    , public FixedStrike
{
public:
            PathIndependentOption (OptionNature* nature, size_t maturity, double strike);
    virtual ~PathIndependentOption();

    virtual void   print(std::ostream& os) const;
    virtual double payoff(double spot)     const = 0;
};


#endif // PathIndependentOption_h
