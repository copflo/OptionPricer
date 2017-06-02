#ifndef UP_h
#define UP_h

#include <vector>

class Up 
{
public:
    Up ();
    ~Up();

    bool        operator()(double barrier, const std::vector<double>& spot_path) const;
    std::string toString  ()                                                     const;
};

#endif /* UP_h */