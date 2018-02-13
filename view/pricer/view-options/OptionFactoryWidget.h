#ifndef OptionFactoryWidget_h
#define OptionFactoryWidget_h

#include <map>

#include <QComboBox>
#include <QStackedWidget>

#include "CashOrNothingOptionWidget.h"
#include "AsianOptionWidget.h"
#include "BarrierOptionWidget.h"
#include "LookbackOptionWidget.h"
#include "PathIndependentOptionWidget.h"


class OptionFactoryWidget
    : public QWidget
{
    Q_OBJECT

public:
    OptionFactoryWidget(QWidget* parent = nullptr);
    virtual ~OptionFactoryWidget();

    std::string choice() const;

	const PathIndependentOptionWidget& pathIndependentOptionUI() const;
	const CashOrNothingOptionWidget& cashOrNothingOptionUI() const;
	const AsianOptionWidget& asianOptionUI() const;
	const BarrierOptionWidget& barrierOptionUI() const;
	const LookbackOptionWidget& lookbackOptionUI() const;

signals:
    void currentStyleChanged(std::string);
    void currentStyleChanged(const QString&);

private slots:
    void emitChoiceChanged(const QString& optionStyle);
    void setOptionWidget(const QString& optionStyle);

private:
    QComboBox* _comboBox;
    QStackedWidget* _stack;
    PathIndependentOptionWidget* _pathIndependent;
    CashOrNothingOptionWidget* _cashOrNothing;
    AsianOptionWidget* _asian;
    BarrierOptionWidget* _barrier;
    LookbackOptionWidget* _lookback;
    std::map<std::string, QWidget*> _widgetMap;
};


#endif // OptionFactoryWidget_h
