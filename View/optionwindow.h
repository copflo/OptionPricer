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
                                                   double price() const;

private:
    MarketWidget*  _market;
    OptionFactory* _option;
    ModelFactory*  _model;
    UnderlyingWidget* _underlying;
};


template<typename OptionStyle, typename Model>
double OptionWindow::price() const
{
    std::unique_ptr<OptionStyle> option(_option->buildOption<OptionStyle>());
    std::unique_ptr<Model> model(_model->buildModel<Model>());
    return model->price(_market->riskfreeRate(), _market->currentSpot(), *option);
}

#endif // OPTIONWINDOW_H
