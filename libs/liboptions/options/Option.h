#ifndef Option_h
#define Option_h

#include <iostream>
#include <memory>
#include <string>

#include "Call.h"
#include "Put.h"


/*!
 * @brief Base class for all options classes
 */
class Option
{
public:

    /*!
     * @brief Contructor for the Option class
     *
     * @param   nature      the nature of the option. Can be Call* or Put*
     * @param   maturity    the maturity of the option expressed in days
     */
    Option(OptionNature* nature, size_t maturity);

    virtual ~Option();

    /*!
     * @brief Indicates if the option is a call
     *
     * @return true if the option is a call, false if it is a put
     */
    bool isCall() const;

    /*!
     * @brief Indicates if the option is a put
     *
     * @return true if the option is a put, false if it is a call
     */
    bool isPut() const;

    /*!
     * @brief Accessor on the maturity attribute
     *
     * @return the maturity of the option
     */
    size_t maturity() const;

    /*!
     * @brief Prints the option in the output stream
     *
     * @param   os  the output stream
     */
    virtual void print(std::ostream& os) const;

    /*!
     * @brief Returns the type of the option as a string
     */
    virtual std::string style() const = 0;

protected:
    std::unique_ptr<OptionNature> _nature;
    size_t _maturity;
};

/*!
 * @brief Overloads the << operator for the Option class
 */
std::ostream& operator<<(std::ostream& os, const Option& option);


#endif // Option_h
