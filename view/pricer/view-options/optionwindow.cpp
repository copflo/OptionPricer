#include <QLCDNumber>
#include <QMessageBox>
#include <QPushButton>

#include "optionwindow.h"


OptionWindow::OptionWindow(QWidget*parent)
    : QWidget(parent)
    , _market(new MarketWidget)
    , _optionFactory(new OptionFactoryWidget)
    , _modelFactory(new ModelFactoryWidget)
    , _underlying(new UnderlyingWidget)
    , _controller(*_market, *_optionFactory, *_modelFactory)
{
    QGridLayout* layout = new QGridLayout(this);

    layout->addWidget(_underlying, 0, 0);
    layout->addWidget(_market, 1, 0);
    layout->addWidget(_optionFactory, 1, 1);
    layout->addWidget(_modelFactory, 1, 2);

    QLCDNumber* priceDisplayer = new QLCDNumber;
    priceDisplayer->setSegmentStyle(QLCDNumber::Flat);
    layout->addWidget(priceDisplayer, 2, 1);

    QPushButton* btn = new QPushButton(QIcon("../icons/price.jpg"), "Price");
    layout->addWidget(btn, 2, 2);

    connect(btn, SIGNAL(clicked(bool)), &_controller, SLOT(priceOption()));
    connect(&_controller, SIGNAL(optionPriced(double)), priceDisplayer, SLOT(display(double)));
}
