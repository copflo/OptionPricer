#ifndef OptionNature_H
#define OptionNature_H

#include <string>


class OptionNature
{
public:
    virtual bool        isCall  ()                           const = 0;
    virtual bool        isPut   ()                           const = 0;
    virtual double      payoff  (double spot, double strike) const = 0;
    virtual std::string toString()                           const = 0;
};


#endif // OptionNature_H
