#ifndef AmericanOption_h
#define AmericanOption_h

#include "VanillaOption.h"


/*!
 * @brief Class for American options
 */
class AmericanOption
    : public VanillaOption
{
public:

    /*!
     * @brief Contructor for the AmericanOption class
     *
     * @param   nature      the nature of the option. Can be Call* or Put*
     * @param   maturity    the maturity of the option expressed in days
     * @param   strike      the strike of the option
     */
    AmericanOption (OptionNature* nature, size_t maturity, double strike);

    virtual ~AmericanOption();

    virtual std::string style() const;
};


#endif // AmericanOption_h
