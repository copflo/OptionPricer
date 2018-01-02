#ifndef STRIKEWIDGET_H
#define STRIKEWIDGET_H

#include <QDoubleSpinBox>
#include <QHBoxLayout>


class StrikeWidget
    : public QWidget
{
    Q_OBJECT

private:
    static double _bufferValue;

public:
    StrikeWidget(QWidget* parent = nullptr);

    virtual double strike() const;

protected:
    virtual void showEvent(QShowEvent* event);

private slots:
    void updateBufferValue(double value);

protected:
    QBoxLayout* _layout;
    QDoubleSpinBox* _strike;
};


#endif // STRIKEWIDGET_H
