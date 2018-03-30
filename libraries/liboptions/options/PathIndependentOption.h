#ifndef PathIndependentOption_h
#define PathIndependentOption_h

#include "FixedStrike.h"
#include "Option.h"


/*!
 * @brief Base class for path-independent options
 */
class PathIndependentOption
    : public Option
    , public FixedStrike
{
public:

    /*!
     * @brief Contructor for the PathIndependentOption class
     *
     * @param   nature      the nature of the option. Can be Call* or Put*
     * @param   maturity    the maturity of the option expressed in days
     * @param   strike      the strike of the option
     */
    PathIndependentOption(OptionNature* nature, size_t maturity, double strike);

    virtual ~PathIndependentOption();

    /*!
     * @brief Computes the payoff of the option for a given underlying price
     *
     * @param   spot    the underlying price
     * @return the payoff of the option
     */
    virtual double payoff(double spot) const = 0;

    /*!
     * @brief Prints the option in the output stream
     *
     * @param   os  the output stream
     */
    virtual void print(std::ostream& os) const;
};


#endif // PathIndependentOption_h
