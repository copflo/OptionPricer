#ifndef BinomialTreeFactory_h
#define BinomialTreeFactory_h

#include <QSpinBox>
#include <QDoubleSpinBox>

#include "options/BinomialTree.h"


class BinomialTreeFactory
    : public QWidget
{
public:
            BinomialTreeFactory (QWidget* parent = nullptr);
    virtual ~BinomialTreeFactory();

    BinomialTree* buildModel() const;

private:
    QLayout* buildParameterLayout(QDoubleSpinBox* widget);

private:
    QSpinBox*       _nbSteps;
    QDoubleSpinBox* _increase;
    QDoubleSpinBox* _decrease;
};


#endif // BinomialTreeFactory_h
