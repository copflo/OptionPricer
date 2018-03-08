#include <cmath>
#include <stdexcept>


#define PI 3.14159265359


double std_normal_pdf(double value)
{
    return (1. / sqrt(2. * PI)) * exp(-0.5 * value * value);
}


double std_normal_cdf(double value)
{
    return 0.5 * (1 + erf(value / sqrt(2.0)));
}

double inverse_std_normal_cdf(double value)
{
    if (value <= 0) {
        throw std::runtime_error("A probability cannot be negative");
    }

    if (value >= 1) {
        throw std::runtime_error("A probability cannot exceed 1");
    }

    static const double a1 = -39.69683028665376;
    static const double a2 = 220.9460984245205;
    static const double a3 = -275.9285104469687;
    static const double a4 = 138.3577518672690;
    static const double a5 = -30.66479806614716;
    static const double a6 = 2.506628277459239;

    static const double b1 = -54.47609879822406;
    static const double b2 = 161.5858368580409;
    static const double b3 = -155.6989798598866;
    static const double b4 = 66.80131188771972;
    static const double b5 = -13.28068155288572;

    static const double c1 = -0.007784894002430293;
    static const double c2 = -0.3223964580411365;
    static const double c3 = -2.400758277161838;
    static const double c4 = -2.549732539343734;
    static const double c5 = 4.374664141464968;
    static const double c6 = 2.938163982698783;

    static const double d1 = 0.007784695709041462;
    static const double d2 = 0.3224671290700398;
    static const double d3 = 2.445134137142996;
    static const double d4 = 3.754408661907416;

    //Define break-points.
    static const double p_low = 0.02425;
    static const double p_high = 1 - p_low;
    long double  q, r, e, u;
    long double x = 0.0;

    //Rational approximation for lower region.
    if (value < p_low) {
        q = sqrt(-2 * log(value));
        x = (((((c1*q + c2)*q + c3)*q + c4)*q + c5)*q + c6) / ((((d1*q + d2)*q + d3)*q + d4)*q + 1);
    }

    //Rational approximation for central region.
    if (p_low <= value && value <= p_high) {
        q = value - 0.5;
        r = q*q;
        x = (((((a1*r + a2)*r + a3)*r + a4)*r + a5)*r + a6)*q / (((((b1*r + b2)*r + b3)*r + b4)*r + b5)*r + 1);
    }

    //Rational approximation for upper region.
    if (p_high < value && value < 1) {
        q = sqrt(-2 * log(1 - value));
        x = -(((((c1*q + c2)*q + c3)*q + c4)*q + c5)*q + c6) / ((((d1*q + d2)*q + d3)*q + d4)*q + 1);
    }

    //Pseudo-code algorithm for refinement
    e = 0.5 * erfc(-x / sqrt(2)) - value;
    u = e * sqrt(2 * 3.14159265359) * exp(x*x / 2);
    return x - u / (1 + x*u / 2);
}
