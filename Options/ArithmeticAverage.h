#ifndef ArithmeticAverage_h
#define ArithmeticAverage_h

#include <vector>

class ArithmeticAverage 
{
public:
    ArithmeticAverage();
    ~ArithmeticAverage();

    double      operator()(const std::vector<double>& values) const;
    std::string toString  ()                                  const;
};

#endif /* ArithmeticAverage_h */
