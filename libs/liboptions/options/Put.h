#ifndef Put_H
#define Put_H

#include "OptionNature.h"


class Put
    : public OptionNature
{
public:
    virtual bool        isCall  ()                           const;
    virtual bool        isPut   ()                           const;
    virtual double      payoff  (double spot, double strike) const;
    virtual std::string toString()                           const;
};


#endif // Put_H
