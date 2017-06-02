#ifndef LookbackOption_h
#define LookbackOption_h

#include "PathDependentOption.h"

class LookbackOption 
    : public PathDependentOption
{
public:
            LookbackOption(Nature nature, int maturity, int obsFreq);
    virtual ~LookbackOption();

    virtual std::string style() const;
};

#endif /* LookbackOption_h */