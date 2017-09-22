#include <QFormLayout>

#include "UnderlyingWidget.h"


UnderlyingWidget::UnderlyingWidget(QWidget* parent)
    : QWidget(parent)
    , _marketPlace(new QLineEdit)
    , _underlying(new QLineEdit)
    , _isin(new QLineEdit)
    , _name(new QLineEdit)
{
    QFormLayout* layout = new QFormLayout(this);
    layout->addRow("Market place", _marketPlace);
    layout->addRow("Underlying", _underlying);
    layout->addRow("ISIN", _isin);
    layout->addRow("Name", _name);

    _name->setEnabled(false);
    _isin->setEnabled(false);
}

UnderlyingWidget::~UnderlyingWidget()
{
}
