#include <algorithm>
#include "Up.h"

Up::Up()
{
}

Up::~Up()
{
}

bool Up::operator()(double barrier, const std::vector<double>& spot_path) const
{
    return std::any_of(spot_path.begin(), spot_path.end(), 
        [barrier](double spot) { return spot >= barrier; });
}

std::string Up::toString() const
{
    return "Up";
}
