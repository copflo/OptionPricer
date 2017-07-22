#ifndef ArithmeticAverage_h
#define ArithmeticAverage_h

#include <vector>

class ArithmeticAverage 
{
public:
    template<class InputIterator>
    static double      average (InputIterator first, InputIterator last);
    static double      average (const std::vector<double>& values);
    static std::string toString();
};


template<class InputIterator>
double ArithmeticAverage::average(InputIterator first, InputIterator last)
{
    return std::accumulate(first, last, 0.0) / values.size();
}

#endif /* ArithmeticAverage_h */
