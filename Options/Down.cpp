#include <algorithm>
#include "Down.h"

Down::Down()
{
}

Down::~Down()
{
}

bool Down::operator()(double barrier, const std::vector<double>& spot_path) const
{
    return std::any_of(spot_path.begin(), spot_path.end(), 
        [barrier](double spot) { return spot <= barrier; });
}

std::string Down::toString() const
{
    return "Down";
}
