#ifndef CrossedBarrierDownwards_h
#define CrossedBarrierDownwards_h

#include <vector>
#include <string>

class Down
{
public:
    Down ();
    ~Down();

    bool        operator()(double barrier, const std::vector<double>& spot_path) const;
    std::string toString  ()                                                     const;
};

#endif /* CrossedBarrierDownwards_h */
