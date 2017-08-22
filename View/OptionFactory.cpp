#include <QStackedWidget>

#include "OptionFactory.h"


const QString OptionFactory::AMERICAN = "American";
const QString OptionFactory::ASSET_OR_NOTHING = "Asset-or-nothing";
const QString OptionFactory::CASH_OR_NOTHING = "Cash-or-nothing";
const QString OptionFactory::EUROPEAN = "European";
const QString OptionFactory::ASIAN = "Asian";
const QString OptionFactory::BARRIER = "Barrier";
const QString OptionFactory::LOOKBACK = "Lookback";


OptionFactory::OptionFactory(QWidget* parent)
    : QWidget(parent)
    , _comboBox(new QComboBox)
    , _american(new AmericanOptionFactory)
    , _assetOrNothing(new AssetOrNothingOptionFactory)
    , _cashOrNothing(new CashOrNothingOptionFactory)
    , _european(new EuropeanOptionFactory)
    , _asian(new IAsianOptionFactory)
    , _barrier(new IBarrierOptionFactory)
    , _lookback(new LookbackOptionFactory)
{
    QBoxLayout* layout = new QVBoxLayout(this);

    _comboBox->addItem(QIcon("icons/american.png"), AMERICAN);
    _comboBox->addItem(QIcon("icons/asian.png"), ASIAN);
    _comboBox->addItem(QIcon("icons/asset-or-nothing.jpg"), ASSET_OR_NOTHING);
    _comboBox->addItem(QIcon("icons/barrier.jpg"), BARRIER);
    _comboBox->addItem(QIcon("icons/cash-or-nothing"), CASH_OR_NOTHING);
    _comboBox->addItem(QIcon("icons/european.png"), EUROPEAN);
    _comboBox->addItem(QIcon("icons/lookback.png"), LOOKBACK);

    QStackedWidget* stack = new QStackedWidget;
    stack->addWidget(_american);
    stack->addWidget(_asian);
    stack->addWidget(_assetOrNothing);
    stack->addWidget(_barrier);
    stack->addWidget(_cashOrNothing);
    stack->addWidget(_european);
    stack->addWidget(_lookback);

    layout->addWidget(_comboBox);
    layout->addWidget(stack);

    connect(_comboBox, SIGNAL(currentIndexChanged(int)),
            stack,     SLOT(setCurrentIndex(int)));

    connect(_comboBox, SIGNAL(currentTextChanged(const QString&)),
            this,      SIGNAL(currentStyleChanged(const QString&)));
}

OptionFactory::~OptionFactory()
{
}

QString OptionFactory::currentStyle() const
{
    return _comboBox->currentText();
}

template<>
AmericanOption* OptionFactory::buildOption<AmericanOption>() const
{
    return _american->buildOption();
}

template<>
AssetOrNothingOption* OptionFactory::buildOption<AssetOrNothingOption>() const
{
    return _assetOrNothing->buildOption();
}

template<>
CashOrNothingOption* OptionFactory::buildOption<CashOrNothingOption>() const
{
    return _cashOrNothing->buildOption();
}

template<>
EuropeanOption* OptionFactory::buildOption<EuropeanOption>() const
{
    return _european->buildOption();
}

template<>
IAsianOption* OptionFactory::buildOption<IAsianOption>() const
{
    return _asian->buildOption();
}

template<>
IBarrierOption* OptionFactory::buildOption<IBarrierOption>() const
{
    return _barrier->buildOption();
}

template<>
ILookbackOption* OptionFactory::buildOption<ILookbackOption>() const
{
    return _lookback->buildOption();
}
