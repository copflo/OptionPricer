#ifndef Volatility_h
#define Volatility_h

class Volatility
{
public:
    Volatility (double value, int = 252);
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

#endif /* Volatility_h */