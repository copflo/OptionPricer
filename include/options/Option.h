#ifndef Option_h
#define Option_h

#include <iostream>
#include <string>


class Option
{
public:
    enum Nature {
        CALL,
        PUT
    };

public:
            Option (Nature nature, int maturity);
    virtual ~Option();

            bool        isCall  ()                 const;
            bool        isPut   ()                 const;
            int         maturity()                 const;
    virtual void        print   (std::ostream& os) const;
    virtual std::string style   ()                 const = 0;

protected:
    std::string nature()                           const;
    double      payoff(double spot, double strike) const;

protected:
    Nature _nature;
    int    _maturity;
};

std::ostream& operator<<(std::ostream& os, const Option& option);


#endif // Option_h
