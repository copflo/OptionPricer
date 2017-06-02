#include <numeric>
#include "GeometricAverage.h"

GeometricAverage::GeometricAverage()
{
}

GeometricAverage::~GeometricAverage()
{
}

double GeometricAverage::operator()(const std::vector<double>& values) const
{
    const double product = std::accumulate(values.begin(), values.end(), 1.0, std::multiplies<double>());
    return pow(product, 1.0 / values.size());
}

std::string GeometricAverage::toString() const
{
    return "Geometric average";
}
