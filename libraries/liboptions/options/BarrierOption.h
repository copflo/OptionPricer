#ifndef BarrierOption_h
#define BarrierOption_h

#include "Down.h"
#include "IBarrierOption.h"
#include "KnockIn.h"
#include "KnockOut.h"
#include "Up.h"


/*!
 * @brief template class for barrier options
 *
 * @tparam  Direction   Can be Up or Down
 * @tparam  Knock       Can be Knockin or Knockout
 */
template<class Direction, class Knock>
class BarrierOption
    : public IBarrierOption
{
public:

    /*!
     * @brief Contructor for the BarrierOption class
     *
     * @param   nature      the nature of the option. Can be Call* or Put*
     * @param   maturity    the maturity of the option expressed in days
     * @param   obsFreq     the observation frequency in days: every day,
     *                      2 days, ...
     * @param   strike      the strike of the option
     * @param   barrier     the barrier of the option
     */
    BarrierOption(OptionNature* nature,
                  size_t maturity,
                  size_t obsFreq,
                  double strike,
                  double barrier);

    virtual ~BarrierOption();

    /*!
     * @brief Returns the payoff of the option for a given underlying price path
     *
     * @param   spot_path   the underlying price path
     * @return the payoff of the option
     */
    virtual double payoff(const std::vector<double>& spot_path) const;

    /*!
     * @brief Prints the option in the output stream
     *
     * @param   os  the output stream
     */
    virtual void print(std::ostream& os) const;
};


template<class Direction, class Knock>
BarrierOption<Direction, Knock>::BarrierOption(OptionNature* nature,
                                               size_t maturity,
                                               size_t obsFreq,
                                               double strike,
                                               double barrier)
    : IBarrierOption(nature, maturity, obsFreq, strike, barrier)
{
}

template<class Direction, class Knock>
BarrierOption<Direction, Knock>::~BarrierOption()
{
}

template<class Direction, class Knock>
double BarrierOption<Direction, Knock>::payoff(const std::vector<double>& spot_path) const
{
    return Knock::activated(Direction::barrierIsCrossed(_barrier, spot_path)) ?
            _nature->payoff(spot_path.back(), _strike) : 0.0;
}

template<class Direction, class Knock>
void BarrierOption<Direction, Knock>::print(std::ostream& os) const
{
    Option::print(os);
    os << Direction::toString() << " and " << Knock::toString() << std::endl;
    os << "Strike: " << _strike << std::endl;
    os << "Barrier: " << _barrier << std::endl;
}


typedef BarrierOption<Up, KnockIn> UpInBarrierOption;
typedef BarrierOption<Down, KnockIn> DownInBarrierOption;
typedef BarrierOption<Up, KnockOut> UpOutBarrierOption;
typedef BarrierOption<Down, KnockOut> DownOutBarrierOption;


#endif // BarrierOption_h
