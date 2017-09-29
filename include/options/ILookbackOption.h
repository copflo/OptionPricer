#ifndef ILookbackOption_h
#define ILookbackOption_h

#include "PathDependentOption.h"


class ILookbackOption
    : public PathDependentOption
{
public:
            ILookbackOption(Nature nature, int maturity, int obsFreq);
    virtual ~ILookbackOption();

    virtual std::string style() const;
};

#endif // ILookbackOption_h
