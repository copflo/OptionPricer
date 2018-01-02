#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>

#include "options/Call.h"
#include "options/Put.h"

#include "BaseOptionWidget.h"


BaseOptionWidget::BaseOptionWidget(QWidget *parent)
    : QWidget(parent)
    , _layout  (new QFormLayout(this))
    , _nature  (new OptionNatureWidget)
    , _maturity(new MaturityWidget)
{
    _layout->addRow(_nature);
    _layout->addRow("Maturity", _maturity);
}

OptionNature* BaseOptionWidget::optionNature() const
{
    return _nature->optionNature();
}

size_t BaseOptionWidget::maturity() const
{
    return _maturity->maturity();
}
