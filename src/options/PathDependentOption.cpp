#include <stdexcept>

#include "PathDependentOption.h"


PathDependentOption::PathDependentOption(OptionNature* nature, size_t maturity, size_t obsFreq)
    : Option(nature, maturity)
    , _obsFreq(obsFreq)
{
    if (maturity < obsFreq) {
        throw std::runtime_error("An observation period cannot be greater than the maturity of the option");
    }
}

PathDependentOption::~PathDependentOption()
{
}

int PathDependentOption::observationFrequency() const
{
    return _obsFreq;
}
