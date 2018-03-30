#include <cmath>

#include "GeometricAverage.h"


double GeometricAverage::average(const std::vector<double>& values)
{
    const double product = std::accumulate(values.begin(), values.end(), 1.0, std::multiplies<double>());
    return pow(product, 1.0 / values.size());
}

std::string GeometricAverage::toString()
{
    return "Geometric average";
}
