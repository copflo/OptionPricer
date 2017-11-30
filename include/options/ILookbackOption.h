#ifndef ILookbackOption_h
#define ILookbackOption_h

#include "PathDependentOption.h"


class ILookbackOption
    : public PathDependentOption
{
public:
            ILookbackOption(OptionNature* nature, size_t maturity, size_t obsFreq);
    virtual ~ILookbackOption();

    virtual std::string style() const;
};

#endif // ILookbackOption_h
