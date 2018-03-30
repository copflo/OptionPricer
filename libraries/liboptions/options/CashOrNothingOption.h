#ifndef CashOrNothingOption_h
#define CashOrNothingOption_h

#include "DigitalOption.h"


/*!
 * @brief Class for cash-or-nothing options
 */
class CashOrNothingOption
    : public DigitalOption
{
public:

    /*!
     * @brief Contructor for the CashOrNothingOption class
     *
     * @param   nature      the nature of the option. Can be Call* or Put*
     * @param   maturity    the maturity of the option expressed in days
     * @param   strike      the strike of the option
     * @param   rebate      the rebate of the option
     */
    CashOrNothingOption(OptionNature* nature,
                        size_t maturity,
                        double strike,
                        double rebate);

    virtual ~CashOrNothingOption();

    double rebate() const;

    /*!
     * @brief Returns the payoff of the option for a given underlying price at
     * maturity
     *
     * @param   spot    the underlying price at maturity
     * @return the payoff of the option
     */
    virtual double payoff(double spot) const;

    virtual std::string style() const;

    /*!
     * @brief Prints the option in the output stream
     *
     * @param   os  the output stream
     */
    virtual void print(std::ostream& os) const;

private:
    double _rebate;
};


#endif // CashOrNothingOption_h
