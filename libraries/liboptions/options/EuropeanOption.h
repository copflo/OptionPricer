#ifndef EuropeanOption_h
#define EuropeanOption_h

#include "VanillaOption.h"


/*!
 * @brief Class for European options
 */
class EuropeanOption
    : public VanillaOption
{
public:

    /*!
     * @brief Contructor for the EuropeanOption class
     *
     * @param   nature      the nature of the option. Can be Call* or Put*
     * @param   maturity    the maturity of the option expressed in days
     * @param   strike      the strike of the option
     */
    EuropeanOption(OptionNature* nature, size_t maturity, double strike);

    virtual ~EuropeanOption();

    virtual std::string style() const;
};


#endif // EuropeanOption_h
