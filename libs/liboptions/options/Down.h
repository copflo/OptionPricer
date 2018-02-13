#ifndef CrossedBarrierDownwards_h
#define CrossedBarrierDownwards_h

#include <vector>
#include <string>


class Down
{
public:
    static bool        barrierIsCrossed(double barrier, const std::vector<double>& spot_path);
    static std::string toString();
};


#endif // CrossedBarrierDownwards_h
