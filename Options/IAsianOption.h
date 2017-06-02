#ifndef IAsianOption_h
#define IAsianOption_h

#include <memory>
#include "PathDependentOption.h"

class IAsianOption 
    : public PathDependentOption
{
public:
            IAsianOption (Nature nature, int maturity, int obsFreq);
    virtual ~IAsianOption();

    virtual std::string style() const;
};

#endif /* IAsianOption_h */