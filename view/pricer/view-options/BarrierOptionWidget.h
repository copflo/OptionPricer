#ifndef BarrierOptionWidget_h
#define BarrierOptionWidget_h

#include "strikewidget.h"
#include "pathdependentoptionwidget.h"


class BarrierOptionWidget
    : public PathDependentOptionWidget
{
private:
    static QWidget* buildGroupBox(const QString& title,
                                  QRadioButton* first,
                                  QRadioButton* second);

public:
            BarrierOptionWidget (QWidget* parent = nullptr);
    virtual ~BarrierOptionWidget();

    double strike() const;
	double barrier() const;
    bool barrierIsUp() const;
    bool barrierIsIn() const;

private:
    QRadioButton* _up;
    QRadioButton* _down;
    QRadioButton* _in;
    QRadioButton* _out;
    StrikeWidget*   _strike;
    QDoubleSpinBox* _barrier;
};


#endif // BarrierOptionWidget_h
