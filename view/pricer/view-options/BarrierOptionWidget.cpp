#include <QGroupBox>

#include "BarrierOptionWidget.h"


QWidget* BarrierOptionWidget::buildGroupBox(const QString& title,
                                            QRadioButton* first,
                                            QRadioButton* second)
{
    QGroupBox* box = new QGroupBox(title);
    QBoxLayout* boxLayout = new QHBoxLayout(box);
    first->setChecked(true);
    boxLayout->addWidget(first);
    boxLayout->addWidget(second);
    return box;
}


BarrierOptionWidget::BarrierOptionWidget(QWidget* parent)
    : PathDependentOptionWidget(parent)
    , _up     (new QRadioButton("Up"))
    , _down   (new QRadioButton("Down"))
    , _in     (new QRadioButton("In"))
    , _out    (new QRadioButton("Out"))
    , _strike (new StrikeWidget)
    , _barrier(new QDoubleSpinBox)
{
    _layout->addRow(buildGroupBox("Direction", _up, _down));
    _layout->addRow(buildGroupBox("Knock", _in, _out));
    _layout->addRow("Strike", _strike);

    _barrier->setRange(0.0, 900.);
    _barrier->setValue(54.);
    _layout->addRow("Barrier", _barrier);
}

BarrierOptionWidget::~BarrierOptionWidget()
{
}

double BarrierOptionWidget::strike() const
{
    return _strike->strike();
}

double BarrierOptionWidget::barrier() const
{
	return _barrier->value();
}

bool BarrierOptionWidget::barrierIsUp() const
{
    return _up->isChecked();
}

bool BarrierOptionWidget::barrierIsIn() const
{
    return _in->isChecked();
}
