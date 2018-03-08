#ifndef LookbackOption_h
#define LookbackOption_h

#include "FixedStrike.h"
#include "FloatingStrike.h"
#include "ILookbackOption.h"


/*!
 * @brief template class for lookback options
 *
 * @tparam  StrikeFloatingness  Indicates wether the option has a fixed strike
 *                              or not
 */
template<class StrikeFloatingness>
class LookbackOption;


/*!
 * @brief template specialization class for lookback options with fixed strike
 */
template<>
class LookbackOption<FixedStrike>
    : public ILookbackOption
    , public FixedStrike
{
public:

    /*!
     * @brief Contructor for the LookbackOption<FixedStrike> class
     *
     * @param   nature      the nature of the option. Can be Call* or Put*
     * @param   maturity    the maturity of the option expressed in days
     * @param   obsFreq     the observation frequency in days: every day,
     *                      2 days, ...
     * @param   strike      the strike of the option
     */
    LookbackOption(OptionNature* nature,
                   size_t maturity,
                   size_t obsFreq,
                   double strike);

    virtual ~LookbackOption();

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

private:

    /*!
     * @brief Finds the optimal spot for exercising the right to buy or sell
     *
     * @param   spot_path   the underlying price path
     * @return the max if the option is a call, the min if it is a put
     */
    double optimalSpot(const std::vector<double>& spot_path) const;
};


template<>
class LookbackOption<FloatingStrike>
    : public ILookbackOption
    , public FloatingStrike
{
public:

    /*!
     * @brief Contructor for the LookbackOption<FixedStrike> class
     *
     * @param   nature      the nature of the option. Can be Call* or Put*
     * @param   maturity    the maturity of the option expressed in days
     * @param   obsFreq     the observation frequency in days: every day,
     *                      2 days, ...
     */
    LookbackOption(OptionNature* nature, size_t maturity, size_t obsFreq);

    virtual ~LookbackOption();

    /*!
     * @brief Returns the payoff of the option for a given underlying price path
     *
     * @param   spot_path   the underlying price path
     * @return the payoff of the option
     */
    virtual double payoff(const std::vector<double>& spot_path) const;

    /*!
     * @brief Computes the strike of the option from a given underlying price path
     *
     * @param   spot_path   the underlying price path
     * @return the min if the option is a call, the max if it is a put
     */
    virtual double strike(const std::vector<double>& spot_path) const;

    /*!
     * @brief Prints the option in the output stream
     *
     * @param   os  the output stream
     */
    virtual void print(std::ostream& os) const;
};


#endif // LookbackOption_h
