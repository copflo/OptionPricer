#include <QGroupBox>
#include "IBarrierOptionFactory.h"


IBarrierOptionFactory::IBarrierOptionFactory(QWidget* parent)
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

IBarrierOptionFactory::~IBarrierOptionFactory()
{
}

IBarrierOption* IBarrierOptionFactory::buildOption() const
{
    return _build.at({ getDirection(), getKnock() })();
}


IBarrierOptionFactory::Direction IBarrierOptionFactory::getDirection() const
{
    return (_up->isChecked()) ? UP : DOWN;
}

IBarrierOptionFactory::Knock IBarrierOptionFactory::getKnock() const
{
    return (_in->isChecked()) ? IN : OUT;
}

QWidget* IBarrierOptionFactory::buildGroupBox(const QString& title, QRadioButton* first, QRadioButton* second)
{
    QGroupBox* box = new QGroupBox(title);

    QBoxLayout* boxLayout = new QHBoxLayout(box);
    first->setChecked(true);
    boxLayout->addWidget(first);
    boxLayout->addWidget(second);

    return box;
}
