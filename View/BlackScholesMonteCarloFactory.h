#ifndef BlackScholesMonteCarloFactory_h
#define BlackScholesMonteCarloFactory_h

#include <QCheckBox>
#include <QSpinBox>

#include "../Models/BlackScholesMonteCarlo.h"

#include "volatilitywidget.h"

class BlackScholesMonteCarloFactory 
    : public QWidget
{
public:
    BlackScholesMonteCarloFactory (QWidget* parent = nullptr);
    ~BlackScholesMonteCarloFactory();

    BlackScholesMonteCarlo* buildModel() const;

private:
    VolatilityWidget* _volatility;

    QCheckBox* _nbObs;
    QSpinBox* _numberOfObs;

    QCheckBox* _timeLimit;
    QDoubleSpinBox* _calculusTime;
};

#endif /* BlackScholesMonteCarloFactory_h */

