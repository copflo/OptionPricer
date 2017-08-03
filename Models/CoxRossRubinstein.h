#ifndef CoxRossRubinstein_h
#define CoxRossRubinstein_h

#include "../Options/VanillaOption.h"

class CoxRossRubinstein
{
private:
    static double binomialValue(double r, double p, double upSpot, double downSpot);

public:
            CoxRossRubinstein (double up, double down, size_t nbSteps);
    virtual ~CoxRossRubinstein();

    double price(double risklessRate, double currentSpot, const VanillaOption& option) const;

private:
    //Probability of getting "up" under p*
    double neutralProba (double risklessRate)                                                                           const; 
    double optionValue  (const VanillaOption& option, double risklessRate, double p, double currentSpot, size_t stepNo) const;

private:
    const double _up;
    const double _down;
    const size_t _nbSteps;
};

#endif /* CoxRossRubinstein_h */