#ifndef MATURITYWIDGET_H
#define MATURITYWIDGET_H

#include <QLabel>
#include <QSpinBox>


class MaturityWidget
    : public QWidget
{
    Q_OBJECT

private:
    static int _bufferValue;

public:
    explicit MaturityWidget(QWidget *parent = nullptr);

    size_t maturity() const;

protected:
    virtual void showEvent(QShowEvent* event);

private slots:
    void updateBuffer(int value);
    void setPlural(int value);

private:
    QSpinBox* _maturity;
    QLabel* _day;
};


#endif // MATURITYWIDGET_H
