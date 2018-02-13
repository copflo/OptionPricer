#ifndef Option_h
#define Option_h

#include <iostream>
#include <memory>
#include <string>

#include "Call.h"
#include "Put.h"


class Option
{
public:
            Option (OptionNature* nature, size_t maturity);
    virtual ~Option();

    bool    isCall  () const;
    bool    isPut   () const;
    size_t  maturity() const;

    virtual void        print(std::ostream& os) const;
    virtual std::string style()                 const = 0;

protected:
    std::unique_ptr<OptionNature> _nature;
    size_t                        _maturity;
};

std::ostream& operator<<(std::ostream& os, const Option& option);


#endif // Option_h
