#ifndef PathDependentOption_h
#define PathDependentOption_h

#include <vector>

#include "Option.h"


/*!
 * @brief Base class for path-dependent options
 */
class PathDependentOption
    : public Option
{
public:

    /*!
     * @brief Contructor for the PathDependentOption class
     *
     * @param   nature      the nature of the option. Can be Call* or Put*
     * @param   maturity    the maturity of the option expressed in days
     * @param   obsFreq     the observation frequency in days: every day,
     *                      2 days, ...
     */
    PathDependentOption(OptionNature* nature, size_t maturity, size_t obsFreq);

    virtual ~PathDependentOption();

    /*!
     * @brief Accessor on the observation frequency attribute of the option
     *
     * @return the observation frequency of the option
     */
    size_t observationFrequency() const;

    /*!
     * @brief Computes how many observations there will be along the maturity of
     * the option
     *
     * @return the number of observations during the maturity of the option
     */
    size_t noOfObservations() const;

    /*!
     * @brief Computes the payoff of the option for a given underlying price path
     *
     * @param   spot_path   the underlying price path
     * @return the payoff of the option
     */
    virtual double payoff(const std::vector<double>& spot_path) const = 0;

protected:
    size_t _obsFreq;
};


#endif // PathDependentOption_h
