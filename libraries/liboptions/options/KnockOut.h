#ifndef KnockOut_h
#define KnockOut_h

#include <string>


/*!
 * @brief Class for checking that a product is activated
 */
class KnockOut
{
public:

    /*!
     * @brief Checks that the product is not activated if the barrier is crossed
     *
     * @param   barrierCrossed  boolean indicating if the barrier is crossed
     * @return true if the barrier is not crossed, false otherwise
     */
    static bool activated(bool barrierCrossed);

    /*!
     * @brief Returns a string representation of the class
     * @return \"Out\"
     */
    static std::string toString();
};


#endif // KnockOut_h
