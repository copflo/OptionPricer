#ifndef ArithmeticAverage_h
#define ArithmeticAverage_h

#include <numeric>
#include <string>
#include <vector>


/*!
 * @brief Class for computing the arithmetic average of an iterable or vector
 */
class ArithmeticAverage
{
public:

    /*!
     * @brief Computes the arithmetic average of a range
     *
     * @tparam  InputIterator   the type of iterator
     *
     * @param   first   begin of the range
     * @param   last    end of the range
     * @return the arithmetic average
     */
    template<class InputIterator>
    static double average(InputIterator first, InputIterator last);

    /*!
     * @brief Computes the arithmetic average of a std::vector
     *
     * @param   values   the vector of values whose average is wanted
     * @return the arithmetic average
     */
    static double average(const std::vector<double>& values);

    /*!
     * @brief Returns a string representation of the class
     *
     * @return "Arithmetic average"
     */
    static std::string toString();
};


template<class InputIterator>
double ArithmeticAverage::average(InputIterator first, InputIterator last)
{
    return std::accumulate(first, last, 0.0) / (last - first);
}


#endif // ArithmeticAverage_h
