#ifndef UP_H
#define UP_H

#include <string>
#include <vector>


/*!
 * @brief Class for checking if a barrier has been crossed upwards
 */
class Up
{
public:

    /*!
     * @brief Checks if the barrier has been crossed upwards by the spot
     *
     * @param   barrier the barrier
     * @param   spot    the stock's price
     */
    static bool barrierIsCrossed(double barrier, double spot);

    /*!
     * @brief Checks if the barrier has been crossed upwards in the path
     *
     * @param   barrier     the barrier
     * @param   spot_path   the path followed by the stock's price
     */
    static bool barrierIsCrossed(double barrier, const std::vector<double>& spot_path);

    /*!
     * @brief Gives a string representation of the class
     *
     * @return \"Up\"
     */
    static std::string toString();
};


#endif // UP_H
