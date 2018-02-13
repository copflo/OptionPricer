#ifndef BinomialTreeWidget_h
#define BinomialTreeWidget_h

#include <QSpinBox>
#include <QDoubleSpinBox>


class BinomialTreeWidget
    : public QWidget
{
private:
    static QLayout* buildParameterLayout(QDoubleSpinBox* widget);

public:
            BinomialTreeWidget (QWidget* parent = nullptr);
    virtual ~BinomialTreeWidget();

    double up() const;
    double down() const;
    size_t nbSteps() const;

private:
    QSpinBox*       _nbSteps;
    QDoubleSpinBox* _increase;
    QDoubleSpinBox* _decrease;
};


#endif // BinomialTreeWidget_h
