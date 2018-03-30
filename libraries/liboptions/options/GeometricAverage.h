#ifndef GeometricAverage_h
#define GeometricAverage_h

#include <numeric>
#include <string>
#include <vector>


/*!
 * @brief Class for computing the geometric average of an iterable or vector
 */
class GeometricAverage
{
public:

    /*!
     * @brief Computes the geometric average of a range
     *
     * @tparam  InputIterator   the type of iterator
     *
     * @param   first   begin of the range
     * @param   last    end of the range
     * @return the geometric average
     */
    template<class InputIterator>
    static double average(InputIterator first, InputIterator last);

    /*!
     * @brief Computes the geometric average of a std::vector
     *
     * @param   values   the vector of values whose average is wanted
     * @return the geometric average
     */
    static double average(const std::vector<double>& values);

    /*!
     * @brief Returns a string representation of the class
     *
     * @return "Geometric average"
     */
    static std::string toString();
};


template<class InputIterator>
double GeometricAverage::average(InputIterator first, InputIterator last)
{
    const double product = std::accumulate(first, last, 1.0, std::multiplies<double>());
    return pow(product, 1.0 / (last - first));
}


#endif // GeometricAverage_h
