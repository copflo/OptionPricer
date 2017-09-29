#ifndef CashOrNothingOption_h
#define CashOrNothingOption_h

#include "DigitalOption.h"


class CashOrNothingOption
    : public DigitalOption
{
public:
            CashOrNothingOption (Option::Nature nature, int maturity, double strike, double rebate);
    virtual ~CashOrNothingOption();

            double      rebate()                 const;
    virtual std::string style ()                 const;
    virtual double      payoff(double spot)      const;
    virtual void        print (std::ostream& os) const;

private:
    double _rebate;
};


#endif // CashOrNothingOption_h
