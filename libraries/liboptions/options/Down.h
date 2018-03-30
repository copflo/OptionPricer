#ifndef CrossedBarrierDownwards_h
#define CrossedBarrierDownwards_h

#include <vector>
#include <string>


/*!
 * @brief Class for checking if a barrier has been crossed downwards
 */
class Down
{
public:

    /*!
     * @brief Checks if the barrier has been crossed downwards in the path
     *
     * @param   barrier     the barrier
     * @param   spot_path   the path followed by the stock's price
     */
    static bool barrierIsCrossed(double barrier,
                                 const std::vector<double>& spot_path);

    /*!
     * @brief Gives a string representation of the class
     *
     * @return \"Down\"
     */
    static std::string toString();
};


#endif // CrossedBarrierDownwards_h
