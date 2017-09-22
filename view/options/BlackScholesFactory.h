#ifndef BlackScholesFactory_h
#define BlackScholesFactory_h

#include <QWidget>

#include "options/BlackScholes.h"

#include "volatilitywidget.h"


class BlackScholesFactory 
    : public QWidget
{
public:
            BlackScholesFactory(QWidget* parent = nullptr);
    virtual ~BlackScholesFactory();

    BlackScholes* buildModel() const;

private:
    VolatilityWidget* _volatility;
};


#endif // BlackScholesFactory_h
