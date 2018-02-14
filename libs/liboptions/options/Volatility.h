#ifndef VOLATILITY_H
#define VOLATILITY_H

#include <iostream>


class Volatility
{
public:
    Volatility (double value, size_t = 252);
    ~Volatility();

    double     value     ()              const;
    double     value     (size_t period) const;
    size_t     period    ()              const;
    Volatility volatility(size_t period) const;

private:
    double _value;
    size_t _period;
};

std::ostream& operator<<(std::ostream& os, const Volatility& vol);


#endif // VOLATILITY_H
