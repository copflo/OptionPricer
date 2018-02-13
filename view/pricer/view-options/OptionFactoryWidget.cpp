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
        { Labels::Options::AMERICAN, _pathIndependent },
        { Labels::Options::ASIAN, _asian },
        { Labels::Options::ASSET_OR_NOTHING, _pathIndependent },
        { Labels::Options::BARRIER, _barrier },
        { Labels::Options::CASH_OR_NOTHING, _cashOrNothing },
        { Labels::Options::EUROPEAN, _pathIndependent },
        { Labels::Options::LOOKBACK, _lookback }
    }
{
    QBoxLayout* layout = new QVBoxLayout(this);

    _comboBox->addItem(QIcon("../icons/american.png"), QString::fromStdString(Labels::Options::AMERICAN));
    _comboBox->addItem(QIcon("../icons/asian.png"), QString::fromStdString(Labels::Options::ASIAN));
    _comboBox->addItem(QIcon("../icons/asset-or-nothing.jpg"), QString::fromStdString(Labels::Options::ASSET_OR_NOTHING));
    _comboBox->addItem(QIcon("../icons/barrier.jpg"), QString::fromStdString(Labels::Options::BARRIER));
    _comboBox->addItem(QIcon("../icons/cash-or-nothing.png"), QString::fromStdString(Labels::Options::CASH_OR_NOTHING));
    _comboBox->addItem(QIcon("../icons/european.png"), QString::fromStdString(Labels::Options::EUROPEAN));
    _comboBox->addItem(QIcon("../icons/lookback.jpg"), QString::fromStdString(Labels::Options::LOOKBACK));

    _stack->addWidget(_pathIndependent);
    _stack->addWidget(_asian);
    _stack->addWidget(_barrier);
    _stack->addWidget(_cashOrNothing);
    _stack->addWidget(_lookback);

    layout->addWidget(_comboBox);
    layout->addWidget(_stack);

    connect(_comboBox, SIGNAL(currentTextChanged(const QString&)),
            this,      SLOT(emitChoiceChanged(const QString&)));

    connect(_comboBox, SIGNAL(currentTextChanged(const QString&)),
            this,      SLOT(setOptionWidget(const QString&)));

    connect(_comboBox, SIGNAL(currentTextChanged(const QString&)),
            this,      SIGNAL(currentStyleChanged(const QString&)));
}

OptionFactoryWidget::~OptionFactoryWidget()
{
}

std::string OptionFactoryWidget::choice() const
{
    return _comboBox->currentText().toStdString();
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

void OptionFactoryWidget::emitChoiceChanged(const QString& optionStyle)
{
    emit(currentStyleChanged(optionStyle.toStdString()));
}

void OptionFactoryWidget::setOptionWidget(const QString& optionStyle)
{
    _stack->setCurrentWidget(_widgetMap.at(optionStyle.toStdString()));
}
