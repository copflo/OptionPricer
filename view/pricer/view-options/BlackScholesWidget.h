#ifndef BlackScholesWidget_h
#define BlackScholesWidget_h

#include <QFormLayout>

#include "volatilitywidget.h"


class BlackScholesWidget
    : public QWidget
{
public:
            BlackScholesWidget(QWidget* parent = nullptr);
    virtual ~BlackScholesWidget();

	Volatility volatility() const;

protected:
    QFormLayout* _layout;
    VolatilityWidget* _volatility;
};


#endif // BlackScholesWidget_h
