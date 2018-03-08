#ifndef DigitalOption_h
#define DigitalOption_h

#include "PathIndependentOption.h"


/*!
 * @brief Base class for digital/binary options
 */
class DigitalOption
    : public PathIndependentOption
{
public:

    /*!
     * @brief Contructor for the DigitalOption class
     *
     * @param   nature      the nature of the option. Can be Call* or Put*
     * @param   maturity    the maturity of the option expressed in days
     * @param   strike      the strike of the option
     */
    DigitalOption(OptionNature* nature, size_t maturity, double strike);

    virtual ~DigitalOption();

protected:

    /*!
     * @brief Indicates if the spot is beyond the strike or not
     *
     * @param   spot    the spot
     */
    bool successfulBet(double spot) const;
};


#endif // DigitalOption_h
