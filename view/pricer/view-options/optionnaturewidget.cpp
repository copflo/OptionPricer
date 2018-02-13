#include <QHBoxLayout>

#include "options/Call.h"
#include "options/Put.h"

#include "optionnaturewidget.h"


bool OptionNatureWidget::_callChecked = true;


OptionNatureWidget::OptionNatureWidget(QWidget *parent)
    : QGroupBox("Nature", parent)
    , _call(new QRadioButton("Call"))
    , _put(new QRadioButton("Put"))
{
    QBoxLayout* layout = new QHBoxLayout(this);    
    layout->addWidget(_call);
    layout->addWidget(_put);

    connect(_call, SIGNAL(toggled(bool)), this, SLOT(setCurrentNature(bool)));
}

OptionNature* OptionNatureWidget::nature() const
{
    if(_call->isChecked()) {
        return new Call;
    }
    return new Put;
}

void OptionNatureWidget::showEvent(QShowEvent* event)
{
    if(_callChecked) {
        _call->setChecked(true);
    }
    else{
        _put->setChecked(true);
    }
}

void OptionNatureWidget::setCurrentNature(bool callChecked)
{
    _callChecked = callChecked;
}
