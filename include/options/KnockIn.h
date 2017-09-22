#ifndef KnockIn_h
#define KnockIn_h

#include <string>

class KnockIn 
{
public:
    static bool        activated(bool barrierCrossed);
    static std::string toString();
};

#endif /* KnockIn_h */