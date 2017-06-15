#ifndef KnockOut_h
#define KnockOut_h

#include <string>

class KnockOut 
{
public:
    static bool        activated(bool barrierCrossed);
    static std::string toString();
};

#endif /* KnockOut_h */