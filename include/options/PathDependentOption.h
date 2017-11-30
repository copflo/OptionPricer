#ifndef PathDependentOption_h
#define PathDependentOption_h

#include <vector>

#include "Option.h"


class PathDependentOption
    : public Option
{
public:
            PathDependentOption (OptionNature* nature, size_t maturity, size_t obsFreq);
    virtual ~PathDependentOption();

            int    observationFrequency()                                     const;
    virtual double payoff              (const std::vector<double>& spot_path) const = 0;

protected:
    size_t _obsFreq;
};

#endif // PathDependentOption_h
