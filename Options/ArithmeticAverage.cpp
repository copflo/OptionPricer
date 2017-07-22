#include <numeric>

#include "ArithmeticAverage.h"


double ArithmeticAverage::average(const std::vector<double>& values)
{
    return std::accumulate(values.begin(), values.end(), 0.0) / values.size();
}

std::string ArithmeticAverage::toString()
{
    return "Arithmetic average";
}