#include <algorithm>
#include "Up.h"

bool Up::barrierIsCrossed(double barrier, const std::vector<double>& spot_path) 
{
    return std::any_of(spot_path.begin(), spot_path.end(), 
        [barrier](double spot) { return spot >= barrier; });
}

std::string Up::toString()
{
    return "Up";
}
