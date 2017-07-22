#ifndef GeometricAverage_h
#define GeometricAverage_h

#include <vector>

class GeometricAverage 
{
public:
    template<class InputIterator>
    static double      average(InputIterator first, InputIterator last);
    static double      average(const std::vector<double>& values);
    static std::string toString();
};


template<class InputIterator>
double GeometricAverage::average(InputIterator first, InputIterator last)
{
    const double product = std::accumulate(first, last, 1.0, std::multiplies<double>());
    return pow(product, 1.0 / values.size());
}

#endif /* GeometricAverage_h */
