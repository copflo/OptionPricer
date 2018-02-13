#ifndef OPTIONWINDOW_H
#define OPTIONWINDOW_H


#include "marketwidget.h"
#include "ModelFactoryWidget.h"
#include "OptController.h"
#include "OptionFactoryWidget.h"
#include "UnderlyingWidget.h"


class OptionWindow
    : public QWidget
{
    Q_OBJECT

public:
    OptionWindow(QWidget* parent = nullptr);

private:
    MarketWidget*  _market;
    OptionFactoryWidget* _optionFactory;
    ModelFactoryWidget* _modelFactory;
    UnderlyingWidget* _underlying;
    OptController _controller;
};


#endif // OPTIONWINDOW_H
