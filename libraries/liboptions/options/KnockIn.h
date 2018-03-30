#ifndef KnockIn_h
#define KnockIn_h

#include <string>


/*!
 * @brief Class for checking that a product is activated
 */
class KnockIn
{
public:

    /*!
     * @brief Checks that the product is activated if the barrier is crossed
     *
     * @param   barrierCrossed  boolean indicating if the barrier is crossed
     * @return true if the barrier is crossed, false otherwise
     */
    static bool activated(bool barrierCrossed);

    /*!
     * @brief Returns a string representation of the class
     * @return \"In\"
     */
    static std::string toString();
};


#endif // KnockIn_h
