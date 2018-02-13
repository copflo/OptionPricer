#ifndef OPTCONTROLLER_H
#define OPTCONTROLLER_H

#include "controller_options/Controller.h"

#include "ModelFactoryWidget.h"
#include "marketwidget.h"
#include "OptionFactoryWidget.h"


class OptController
    : public QObject
	, public Controller<MarketWidget, OptionFactoryWidget, ModelFactoryWidget>
{
    Q_OBJECT

public:
    OptController(MarketWidget&        mktWdgt,
				  OptionFactoryWidget& optFactWdgt,
                  ModelFactoryWidget&  modlFactWdgt);
    virtual ~OptController();

signals:
    void optionPriced(double);

public slots:
    void priceOption();

private slots:
	void setAvailableModels(const QString& optionType);
};


#endif // OPTCONTROLLER_H
