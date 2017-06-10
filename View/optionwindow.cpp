#include <QLCDNumber>
#include <QMessageBox>
#include <QPushButton>

#include "optionwindow.h"

OptionWindow::OptionWindow(QWidget*parent)
    : QWidget(parent)
    , _market(new MarketWidget)
    , _option(new OptionFactory)
    , _model(new ModelFactory)
{
    QGridLayout* layout = new QGridLayout(this);

    layout->addWidget(_market, 0, 0);
    layout->addWidget(_option, 1, 1);
    layout->addWidget(_model, 1, 2);

    QLCDNumber* priceDisplayer = new QLCDNumber;
    priceDisplayer->setSegmentStyle(QLCDNumber::Flat);
    layout->addWidget(priceDisplayer, 2, 1);

    QPushButton* btn = new QPushButton("Price");
    layout->addWidget(btn, 2, 2);

    connect(_option, SIGNAL(currentOptionStyleChanged(const QString&)),
            _model, SLOT(update(const QString&)));

    _model->update(_option->getCurrentSelection());

    connect(btn, SIGNAL(clicked(bool)), this, SLOT(priceOption()));
    connect(this, SIGNAL(optionPriced(double)), priceDisplayer, SLOT(display(double)));
}

void OptionWindow::priceOption()
{
    try {
        emit(optionPriced(price()));
    }
    catch (const std::exception& ex) {
        QMessageBox::critical(this, "Error", ex.what());
    }
}

double OptionWindow::price() const 
{
    const QString optionType = _option->getCurrentSelection();
    const QString model = _model->getCurrentSelection();

    if (optionType == OptionFactory::AMERICAN) {
        if (model == ModelFactory::COX_ROSS_RUBINSTEIN) {
            return price<AmericanOption, CoxRossRubinstein>();
        }
    }

    if (optionType == OptionFactory::ASIAN) {
        if (model == ModelFactory::BLACK_SCHOLES_MC) {
            return price<IAsianOption, BlackScholesMonteCarlo>();
        }
    }

    if (optionType == OptionFactory::ASSET_OR_NOTHING) {
        if (model == ModelFactory::BLACK_SCHOLES) {
            return price<AssetOrNothingOption, BlackScholes>();
        }

        if (model == ModelFactory::BLACK_SCHOLES_MC) {
            return price<AssetOrNothingOption, BlackScholesMonteCarlo>();
        }
    }

    if (optionType == OptionFactory::BARRIER) {
        if (model == ModelFactory::BLACK_SCHOLES_MC) {
            return price<IBarrierOption, BlackScholesMonteCarlo>();
        }
    }

    if (optionType == OptionFactory::CASH_OR_NOTHING) {
        if (model == ModelFactory::BLACK_SCHOLES) {
            return price<CashOrNothingOption, BlackScholes>();
        }

        if (model == ModelFactory::BLACK_SCHOLES_MC) {
            return price<CashOrNothingOption, BlackScholesMonteCarlo>();
        }
    }

    if (optionType == OptionFactory::EUROPEAN) {

        if (model == ModelFactory::BLACK_SCHOLES) {
            return price<EuropeanOption, BlackScholes>();
        }

        if (model == ModelFactory::BLACK_SCHOLES_MC) {
            return price<EuropeanOption, BlackScholesMonteCarlo>();
        }

        if (model == ModelFactory::COX_ROSS_RUBINSTEIN) {
            return price<EuropeanOption, CoxRossRubinstein>();
        }
    }

    if (optionType == OptionFactory::LOOKBACK) {
        if (model == ModelFactory::BLACK_SCHOLES_MC) {
            return price<LookbackOption, BlackScholesMonteCarlo>();
        }
    }

    throw std::runtime_error("OptionWindow::price(): Unexpected fallback");
}