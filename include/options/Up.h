#ifndef UP_H
#define UP_H

#include <string>
#include <vector>


class Up 
{
public:
    static bool        barrierIsCrossed(double barrier, const std::vector<double>& spot_path);
    static std::string toString();
};

#endif // UP_H
