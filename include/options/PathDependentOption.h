#ifndef PathDependentOption_h
#define PathDependentOption_h

#include <vector>

#include "Option.h"


class PathDependentOption
    : public Option
{
public:
            PathDependentOption (OptionNature* nature, int maturity, int obsFreq);
    virtual ~PathDependentOption();

            int    observationFrequency()                                     const;
    virtual double payoff              (const std::vector<double>& spot_path) const = 0;

protected:
    int _obsFreq;
};

#endif // PathDependentOption_h
