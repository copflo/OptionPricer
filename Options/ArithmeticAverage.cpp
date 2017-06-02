#include <numeric>
#include "ArithmeticAverage.h"

ArithmeticAverage::ArithmeticAverage()
{
}

ArithmeticAverage::~ArithmeticAverage()
{
}

double ArithmeticAverage::operator()(const std::vector<double>& values) const
{
    return std::accumulate(values.begin(), values.end(), 0.0) / values.size();
}

std::string ArithmeticAverage::toString() const
{
    return "Arithmetic average";
}
