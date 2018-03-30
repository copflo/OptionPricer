#ifndef IAsianOption_h
#define IAsianOption_h

#include <memory>

#include "PathDependentOption.h"


/*!
 * @brief Base class for Asian options
 */
class IAsianOption
    : public PathDependentOption
{
public:

    /*!
     * @brief Contructor for the IAsianOption class
     *
     * @param   nature      the nature of the option. Can be Call* or Put*
     * @param   maturity    the maturity of the option expressed in days
     * @param   obsFreq     the observation frequency in days: every day,
     *                      2 days, ...
     */
    IAsianOption(OptionNature* nature, size_t maturity, size_t obsFreq);

    virtual ~IAsianOption();

    virtual std::string style() const;
};


#endif // IAsianOption_h
