#ifndef KnockOut_h
#define KnockOut_h

#include <string>

class KnockOut 
{
public:
    KnockOut ();
    ~KnockOut();

    bool        activated(bool barrierCrossed) const;
    std::string toString()                     const;
};

#endif /* KnockOut_h */