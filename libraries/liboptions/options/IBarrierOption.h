#ifndef IBarrierOption_h
#define IBarrierOption_h

#include "FixedStrike.h"
#include "PathDependentOption.h"


/*!
 * @brief Base class for barrier options
 */
class IBarrierOption
    : public PathDependentOption
    , public FixedStrike
{
public:

    /*!
     * @brief Constructor for the IBarrierOption class
     *
     * @param   nature      the nature of the option. Can be Call* or Put*
     * @param   maturity    the maturity of the option expressed in days
     * @param   obsFreq     the observation frequency in days: every day,
     *                      2 days, ...
     * @param   strike      the strike of the option
     * @param   barrier     the barrier of the option
     */
    IBarrierOption(OptionNature* nature,
                   size_t maturity,
                   size_t obsFreq,
                   double strike,
                   double barrier);

    virtual ~IBarrierOption();

    /*!
     * @brief Accessor on the barrier attribute of the option
     *
     * @return the barrier of the option
     */
    double barrier() const;

    virtual std::string style() const;

protected:
    double _barrier;
};


#endif // IBarrierOption_h
