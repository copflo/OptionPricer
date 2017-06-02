#ifndef GeometricAverage_h
#define GeometricAverage_h

#include <vector>

class GeometricAverage 
{
public:
    GeometricAverage();
    ~GeometricAverage();

    double      operator()(const std::vector<double>& values) const;
    std::string toString  ()                                  const;
};

#endif /* GeometricAverage_h */