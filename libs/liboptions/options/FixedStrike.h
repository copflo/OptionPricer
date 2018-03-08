#ifndef FixedStrike_h
#define FixedStrike_h


/*!
 * @brief Interface class for derivatives with a predefined fixed strike
 */
class FixedStrike
{
public:

    /*!
     * @brief Constructor for the FixedStrike class
     *
     * @param   strike  the strike
     */
    FixedStrike(double strike);

    virtual ~FixedStrike();

    /*!
     * @brief Accessor on the strike attribute
     *
     * @return the strike
     */
    double strike() const;

protected:
    double _strike;
};


#endif // FixedStrike_h
