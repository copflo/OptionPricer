#include <QLCDNumber>
#include <QMessageBox>
#include <QPushButton>

#include "optionwindow.h"


OptionWindow::OptionWindow(QWidget*parent)
    : QWidget(parent)
    , _market(new MarketWidget)
    , _option(new OptionFactory)
    , _model(new ModelFactory)
    , _underlying(new UnderlyingWidget)
{
    QGridLayout* layout = new QGridLayout(this);
    
    layout->addWidget(_underlying, 0, 0);
    layout->addWidget(_market, 1, 0);
    layout->addWidget(_option, 1, 1);
    layout->addWidget(_model, 1, 2);

    QLCDNumber* priceDisplayer = new QLCDNumber;
    priceDisplayer->setSegmentStyle(QLCDNumber::Flat);
    layout->addWidget(priceDisplayer, 2, 1);

    QPushButton* btn = new QPushButton(QIcon("icons/price.jpg"), "Price");
    layout->addWidget(btn, 2, 2);

    connect(_option, SIGNAL(currentStyleChanged(const QString&)),
            _model, SLOT(update(const QString&)));
    _model->update(_option->currentStyle());

    connect(btn, SIGNAL(clicked(bool)), this, SLOT(priceOption()));
    connect(this, SIGNAL(optionPriced(double)), priceDisplayer, SLOT(display(double)));
}

void OptionWindow::priceOption()
{
    try {
        const double p = _price.at({ _option->currentStyle(), _model->currentModel() })();
        emit(optionPriced(p));
    }
    catch (const std::exception& ex) {
        QMessageBox::critical(this, "Error", ex.what());
    }
}