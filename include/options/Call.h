#ifndef Call_H
#define Call_H

#include "OptionNature.h"


class Call
    : public OptionNature
{
public:
    virtual bool        isCall  ()                           const;
    virtual bool        isPut   ()                           const;
    virtual double      payoff  (double spot, double strike) const;
    virtual std::string toString()                           const;
};


#endif // Call_H
