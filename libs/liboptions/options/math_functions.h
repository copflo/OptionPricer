#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H


/*!
 * @brief Computes the probability density function of a standard Gaussian
 * random variable for a given value
 *
 * @param   value   the value for which the pdf is wanted
 * @return the pdf at <value>
 */
double std_normal_pdf(double value);

/*!
 * @brief Computes the cumulative density function of a standard Gaussian
 * random variable for a given value
 *
 * @param   value   the value for which the cdf is wanted
 * @return the cdf at <value>
 */
double std_normal_cdf(double value);

/*!
 * @brief Computes the inverse of the cumulative density function of a standard
 * Gaussian random variable for a given value
 *
 * @param   value   the value for which the inverse cdf is wanted
 * @return the inverse cdf at <value>
 */
double inverse_std_normal_cdf(double value);


#endif // MATH_FUNCTIONS_H
