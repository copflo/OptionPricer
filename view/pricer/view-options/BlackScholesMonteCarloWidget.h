#ifndef BlackScholesMonteCarloWidget_h
#define BlackScholesMonteCarloWidget_h

#include <QCheckBox>
#include <QSpinBox>

#include "BlackScholesWidget.h"


class BlackScholesMonteCarloWidget
    : public BlackScholesWidget
{
public:
    BlackScholesMonteCarloWidget (QWidget* parent = nullptr);
    virtual ~BlackScholesMonteCarloWidget();

    bool nbObsCondition() const;
    bool timeLimitCondition() const;

    size_t nbObs() const;
    double timeLimit() const;

private:
    QCheckBox* _nbObs;
    QSpinBox* _numberOfObs;
    QCheckBox* _timeLimit;
    QDoubleSpinBox* _calculusTime;
};


#endif // BlackScholesMonteCarloWidget_h
