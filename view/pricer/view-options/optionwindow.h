#ifndef OPTIONWINDOW_H
#define OPTIONWINDOW_H

#include "OptionFactory.h"
#include "ModelFactory.h"
#include "marketwidget.h"
#include "UnderlyingWidget.h"


class OptionWindow
    : public QWidget
{
    Q_OBJECT

public:
    OptionWindow(QWidget* parent = nullptr);

private slots:
    void priceOption();

signals:
    void optionPriced(double);

private:
    template<typename OptionStyle, typename Model> double price() const;

private:
    MarketWidget*  _market;
    OptionFactory* _optionFactory;
    ModelFactory*  _modelFactory;
    UnderlyingWidget* _underlying;

private:
    const std::map<std::pair<QString, QString>, std::function<double()>> _price{

        { { OptionFactory::AMERICAN, ModelFactory::BINOMIAL_TREE },
            std::bind(&OptionWindow::price<AmericanOption, BinomialTree>, this) },

        { { OptionFactory::ASIAN, ModelFactory::ModelFactory::BLACK_SCHOLES_MC },
            std::bind(&OptionWindow::price<IAsianOption, BlackScholesMonteCarlo>, this) },

        { { OptionFactory::ASSET_OR_NOTHING, ModelFactory::BLACK_SCHOLES },
            std::bind(&OptionWindow::price<AssetOrNothingOption, BlackScholes>, this) },

        { { OptionFactory::ASSET_OR_NOTHING, ModelFactory::BLACK_SCHOLES_MC },
            std::bind(&OptionWindow::price<AssetOrNothingOption, BlackScholesMonteCarlo>, this) },

        { { OptionFactory::BARRIER, ModelFactory::BLACK_SCHOLES_MC },
            std::bind(&OptionWindow::price<IBarrierOption, BlackScholesMonteCarlo>, this) },

        { { OptionFactory::CASH_OR_NOTHING, ModelFactory::BLACK_SCHOLES },
            std::bind(&OptionWindow::price<CashOrNothingOption, BlackScholes>, this) },

        { { OptionFactory::CASH_OR_NOTHING, ModelFactory::BLACK_SCHOLES_MC },
            std::bind(&OptionWindow::price<CashOrNothingOption, BlackScholesMonteCarlo>, this) },

        { { OptionFactory::EUROPEAN, ModelFactory::BLACK_SCHOLES },
            std::bind(&OptionWindow::price<EuropeanOption, BlackScholes>, this) },

        { { OptionFactory::EUROPEAN, ModelFactory::BLACK_SCHOLES_MC },
            std::bind(&OptionWindow::price<EuropeanOption, BlackScholesMonteCarlo>, this) },

        { { OptionFactory::EUROPEAN, ModelFactory::BINOMIAL_TREE },
            std::bind(&OptionWindow::price<EuropeanOption, BinomialTree>, this) },

        { { OptionFactory::LOOKBACK, ModelFactory::BLACK_SCHOLES_MC },
            std::bind(&OptionWindow::price<ILookbackOption, BlackScholesMonteCarlo>, this) }
    };
};


template<typename OptionStyle, typename Model>
double OptionWindow::price() const
{
    std::unique_ptr<OptionStyle> option(_optionFactory->buildOption<OptionStyle>());
    std::unique_ptr<Model> model(_modelFactory->buildModel<Model>());
    return model->price(_market->riskfreeRate(), _market->currentSpot(), *option);
}


#endif // OPTIONWINDOW_H
