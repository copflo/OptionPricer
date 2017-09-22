#ifndef CoxRossRubinsteinFactory_h
#define CoxRossRubinsteinFactory_h

#include <QSpinBox>
#include <QDoubleSpinBox>

#include "options/CoxRossRubinstein.h"


class CoxRossRubinsteinFactory 
    : public QWidget
{
public:
            CoxRossRubinsteinFactory (QWidget* parent = nullptr);
    virtual ~CoxRossRubinsteinFactory();

    CoxRossRubinstein* buildModel() const;

private:
    QLayout* buildParameterLayout(QDoubleSpinBox* widget);

private:
    QSpinBox*       _nbSteps;
    QDoubleSpinBox* _increase;
    QDoubleSpinBox* _decrease;
};


#endif // CoxRossRubinsteinFactory_h
