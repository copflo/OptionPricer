#ifndef ILookbackOption_h
#define ILookbackOption_h

#include "PathDependentOption.h"


/*!
 * @brief Base class for lookback options
 */
class ILookbackOption
    : public PathDependentOption
{
public:

    /*!
     * @brief Constructor for the IBarrierOption class
     *
     * @param   nature      the nature of the option. Can be Call* or Put*
     * @param   maturity    the maturity of the option expressed in days
     * @param   obsFreq     the observation frequency in days: every day,
     *                      2 days, ...
     */
    ILookbackOption(OptionNature* nature, size_t maturity, size_t obsFreq);
    
    virtual ~ILookbackOption();

    virtual std::string style() const;
};

#endif // ILookbackOption_h
