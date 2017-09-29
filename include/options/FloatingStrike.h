#ifndef FloatingStrike_h
#define FloatingStrike_h

#include <vector>


class FloatingStrike
{
public:
            FloatingStrike();
    virtual ~FloatingStrike();

    virtual double strike(const std::vector<double>& spot_path) const = 0;
};

#endif // FloatingStrike_h
