#ifndef AsianOption_h
#define AsianOption_h

#include "ArithmeticAverage.h"
#include "GeometricAverage.h"
#include "FixedStrike.h"
#include "FloatingStrike.h"
#include "IAsianOption.h"


/*!
 * @brief template class for Asian options
 *
 * @tparam  Avg                 The type of average.
 *                              Can be ArithmeticAverage or GeometricAverage
 * @tparam  StrikeFloatingness  Indicates wether the option has a fixed strike
 *                              or not
 */
template<class Avg, class StrikeFloatingness>
class AsianOption;


/*!
 * @brief template specialization class for Asian options with fixed strike
 *
 * @tparam  Avg  The type of average. Can be ArithmeticAverage or GeometricAverage
 */
template<class Avg>
class AsianOption<Avg, FixedStrike>
    : public IAsianOption
    , public FixedStrike
{
public:

    /*!
     * @brief Contructor for the AsianOption<Avg, FixedStrike> class
     *
     * @param   nature      the nature of the option. Can be Call* or Put*
     * @param   maturity    the maturity of the option expressed in days
     * @param   obsFreq     the observation frequency in days: every day,
     *                      2 days, ...
     * @param   strike      the strike of the option
     */
    AsianOption(OptionNature* nature,
                size_t maturity,
                size_t obsFreq,
                double strike);

    virtual ~AsianOption();

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


template<class Avg>
AsianOption<Avg, FixedStrike>::AsianOption(OptionNature* nature,
                                           size_t maturity,
                                           size_t obsFreq,
                                           double strike)
    : IAsianOption(nature, maturity, obsFreq)
    , FixedStrike(strike)
{
}

template<class Avg>
AsianOption<Avg, FixedStrike>::~AsianOption()
{
}

template<class Avg>
double AsianOption<Avg, FixedStrike>::payoff(const std::vector<double>& spot_path) const
{
    return _nature->payoff(Avg::average(spot_path), _strike);
}

template<class Avg>
void AsianOption<Avg, FixedStrike>::print(std::ostream& os) const
{
    Option::print(os);
    os << Avg::toString() << std::endl;
    os << "Strike : " << _strike << std::endl;
}


/*!
 * @brief template specialization class for Asian options with floating strike
 *
 * @tparam  Avg  The type of average. Can be ArithmeticAverage or GeometricAverage
 */
template<class Avg>
class AsianOption<Avg, FloatingStrike>
    : public IAsianOption
    , public FloatingStrike
{
public:

    /*!
     * @brief Contructor for the AsianOption<Avg, FloatingStrike> class
     *
     * @param   nature      the nature of the option. Can be Call* or Put*
     * @param   maturity    the maturity of the option expressed in days
     * @param   obsFreq     the observation frequency in days: every day,
     *                      2 days, ...
     */
    AsianOption (OptionNature* nature, size_t maturity, size_t obsFreq);

    virtual ~AsianOption();

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
     * @return the average of the underlying price path
     */
    virtual double strike(const std::vector<double>& spot_path) const;

    /*!
     * @brief Prints the option in the output stream
     *
     * @param   os  the output stream
     */
    virtual void print(std::ostream& os) const;
};


template<class Avg>
AsianOption<Avg, FloatingStrike>::AsianOption(OptionNature* nature,
                                              size_t maturity,
                                              size_t obsFreq)
    : IAsianOption(nature, maturity, obsFreq)
{
}

template<class Avg>
AsianOption<Avg, FloatingStrike>::~AsianOption()
{
}

template<class Avg>
double AsianOption<Avg, FloatingStrike>::payoff(const std::vector<double>& spot_path) const
{
    return _nature->payoff(spot_path.back(), strike(spot_path));
}

template<class Avg>
void AsianOption<Avg, FloatingStrike>::print(std::ostream& os) const
{
    Option::print(os);
    os << Avg::toString() << std::endl;
}

template<class Avg>
double AsianOption<Avg, FloatingStrike>::strike(const std::vector<double>& spot_path) const
{
    return Avg::average(spot_path);
}


#endif // AsianOption_h
