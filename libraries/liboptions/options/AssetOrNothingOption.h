#ifndef AssetOrNothingOption_h
#define AssetOrNothingOption_h

#include "DigitalOption.h"


/*!
 * @brief Class for asset-or-nothing options
 */
class AssetOrNothingOption
    : public DigitalOption
{
public:

    /*!
     * @brief Contructor for the AssetOrNothingOption class
     *
     * @param   nature      the nature of the option. Can be Call* or Put*
     * @param   maturity    the maturity of the option expressed in days
     * @param   strike      the strike of the option
     */
    AssetOrNothingOption(OptionNature* nature, size_t maturity, double strike);

    virtual ~AssetOrNothingOption();

    /*!
     * @brief Returns the payoff of the option for a given underlying price at
     * maturity
     *
     * @param   spot    the underlying price at maturity
     * @return the payoff of the option
     */
    virtual double payoff(double spot) const;

    virtual std::string style() const;
};


#endif // AssetOrNothingOption_h
