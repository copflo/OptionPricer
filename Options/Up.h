#ifndef UP_h
#define UP_h

#include <vector>

class Up 
{
public:
    static bool        barrierIsCrossed(double barrier, const std::vector<double>& spot_path);
    static std::string toString();
};

#endif /* UP_h */