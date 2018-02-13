#ifndef BinomialTree_h
#define BinomialTree_h

#include "AmericanOption.h"
#include "EuropeanOption.h"


class BinomialTree
{
private:
    static double binomialValue(double r, double p, double upSpot, double downSpot);

public:
            BinomialTree (double up, double down, size_t nbSteps);
    virtual ~BinomialTree();

    template<class Opt> double price(double risklessRate, double currentSpot, const Opt& option) const;

private:
    //Probability of getting "up" under p*
    double neutralProba(double risklessRate)                                                                            const;
    double optionValue (const AmericanOption& option, double risklessRate, double p, double currentSpot, size_t stepNo) const;
    double optionValue (const EuropeanOption& option, double risklessRate, double p, double currentSpot, size_t stepNo) const;

private:
    const double _up;
    const double _down;
    const size_t _nbSteps;
};


template<class Opt>
double BinomialTree::price(double risklessRate, double currentSpot, const Opt& option) const
{
    if (!(_down < risklessRate) || !(risklessRate < _up)) {
        throw std::runtime_error("Error in modelization: down < r < up means the market is not arbitrageless");
    }
    return optionValue(option, risklessRate, neutralProba(risklessRate), currentSpot, 0);
}


#endif // BinomialTree_h
