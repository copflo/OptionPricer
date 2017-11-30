#ifndef VOLATILITY_H
#define VOLATILITY_H

#include <iostream>


class Volatility
{
public:
    Volatility (double value, size_t = 252);
    ~Volatility();

    double     value     ()           const;
    double     value     (int period) const;
    int        period    ()           const;
    Volatility volatility(int period) const;

private:
    double _value;
    int    _period;
};

std::ostream& operator<<(std::ostream& os, const Volatility& vol);


#endif // VOLATILITY_H
