#ifndef MAXLIKELIHOOD_H
#define MAXLIKELIHOOD_H

#include <tuple>


class MaxLikelihood
{
public:
    template<typename Iter>
    static double poisson(Iter begin, Iter end);

    template<typename Iter>
    static std::pair<double, double> gaussian(Iter begin, Iter end);

    template<typename Iter>
    static std::pair<double, double> garch_1_1(Iter begin, Iter end);
};


template<typename Iter>
double MaxLikelihood::poisson(Iter begin, Iter end)
{

}


#endif // MAXLIKELIHOOD_H