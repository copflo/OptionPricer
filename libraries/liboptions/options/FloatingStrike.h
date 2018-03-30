#ifndef FloatingStrike_h
#define FloatingStrike_h

#include <vector>


/*!
 * @brief Interface class for derivatives with a floating strike
 */
class FloatingStrike
{
public:

    /*!
     * @brief Constructor for the FloatingStrike class
     */
    FloatingStrike();

    virtual ~FloatingStrike();

    /*!
     * @brief Pure virtual method that computes the strike from a given stock
     * price path
     *
     * @param   spot_path   the path followed by the stock's price
     */
    virtual double strike(const std::vector<double>& spot_path) const = 0;
};

#endif // FloatingStrike_h
