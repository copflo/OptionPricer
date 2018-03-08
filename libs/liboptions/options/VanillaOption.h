#ifndef VanillaOption_h
#define VanillaOption_h

#include "PathIndependentOption.h"


/*!
 * @brief Base class for vanilla options
 */ 
class VanillaOption
    : public PathIndependentOption
{
public:

    /*!
     * @brief Contructor for the VanillaOption class
     *
     * @param   nature      the nature of the option. Can be Call* or Put*
     * @param   maturity    the maturity of the option expressed in days
     * @param   strike      the strike of the option
     */
    VanillaOption(OptionNature* nature, size_t maturity, double strike);

    virtual ~VanillaOption();

     /*!
     * @brief Computes the payoff of the option for a given underlying price
     *
     * @param   spot    the underlying price
     * @return max(spot - strike, 0.0) if the option is a call, 
     * max(strike - spot, 0.0) if the option is a put
     */
    virtual double payoff(double spot) const;
};


#endif // VanillaOption_h
