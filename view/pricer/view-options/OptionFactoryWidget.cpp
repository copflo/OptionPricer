#include "controller_options/Labels.h"

#include "OptionFactoryWidget.h"


OptionFactoryWidget::OptionFactoryWidget(QWidget* parent)
    : QWidget(parent)
    , _comboBox(new QComboBox)
    , _pathIndependent(new PathIndependentOptionWidget)
    , _stack(new QStackedWidget)
    , _cashOrNothing(new CashOrNothingOptionWidget)
    , _asian(new AsianOptionWidget)
    , _barrier(new BarrierOptionWidget)
    , _lookback(new LookbackOptionWidget)
    , _widgetMap{
        { Labels<QString>::Options::AMERICAN, _pathIndependent },
        { Labels<QString>::Options::ASIAN, _asian },
        { Labels<QString>::Options::ASSET_OR_NOTHING, _pathIndependent },
        { Labels<QString>::Options::BARRIER, _barrier },
        { Labels<QString>::Options::CASH_OR_NOTHING, _cashOrNothing },
        { Labels<QString>::Options::EUROPEAN, _pathIndependent },
        { Labels<QString>::Options::LOOKBACK, _lookback }
    }
{
    QBoxLayout* layout = new QVBoxLayout(this);

    _comboBox->addItem(QIcon("../icons/american.png"), Labels<QString>::Options::AMERICAN);
    _comboBox->addItem(QIcon("../icons/asian.png"), Labels<QString>::Options::ASIAN);
    _comboBox->addItem(QIcon("../icons/asset-or-nothing.jpg"), Labels<QString>::Options::ASSET_OR_NOTHING);
    _comboBox->addItem(QIcon("../icons/barrier.jpg"), Labels<QString>::Options::BARRIER);
    _comboBox->addItem(QIcon("../icons/cash-or-nothing.png"), Labels<QString>::Options::CASH_OR_NOTHING);
    _comboBox->addItem(QIcon("../icons/european.png"), Labels<QString>::Options::EUROPEAN);
    _comboBox->addItem(QIcon("../icons/lookback.jpg"), Labels<QString>::Options::LOOKBACK);

    _stack->addWidget(_pathIndependent);
    _stack->addWidget(_asian);
    _stack->addWidget(_barrier);
    _stack->addWidget(_cashOrNothing);
    _stack->addWidget(_lookback);

    layout->addWidget(_comboBox);
    layout->addWidget(_stack);

    connect(_comboBox, SIGNAL(currentTextChanged(const QString&)),
            this,      SLOT(setOptionWidget(const QString&)));

    connect(_comboBox, SIGNAL(currentTextChanged(const QString&)),
            this,      SIGNAL(currentStyleChanged(const QString&)));
}

OptionFactoryWidget::~OptionFactoryWidget()
{
}

QString OptionFactoryWidget::choice() const
{
    return _comboBox->currentText();
}

const PathIndependentOptionWidget& OptionFactoryWidget::pathIndependentOptionUI() const
{
	return *_pathIndependent;
}

const CashOrNothingOptionWidget& OptionFactoryWidget::cashOrNothingOptionUI() const
{
	return *_cashOrNothing;
}

const AsianOptionWidget & OptionFactoryWidget::asianOptionUI() const
{
	return *_asian;
}

const BarrierOptionWidget & OptionFactoryWidget::barrierOptionUI() const
{
	return *_barrier;
}

const LookbackOptionWidget& OptionFactoryWidget::lookbackOptionUI() const
{
	return *_lookback;
}

void OptionFactoryWidget::setOptionWidget(const QString& optionStyle)
{
    _stack->setCurrentWidget(_widgetMap.at(optionStyle));
}
