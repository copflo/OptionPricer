#ifndef KnockIn_h
#define KnockIn_h

#include <string>

class KnockIn 
{
public:
    KnockIn ();
    ~KnockIn();

    bool        activated(bool barrierCrossed) const;
    std::string toString()                     const;
};

#endif /* KnockIn_h */