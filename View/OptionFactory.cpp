#include "OptionFactory.h"

const QString OptionFactory::AMERICAN = "American";
const QString OptionFactory::ASSET_OR_NOTHING = "Asset or nothing";
const QString OptionFactory::CASH_OR_NOTHING = "Cash or nothing";
const QString OptionFactory::EUROPEAN = "European";
const QString OptionFactory::ASIAN = "Asian";
const QString OptionFactory::BARRIER = "Barrier";
const QString OptionFactory::LOOKBACK = "Lookback";

OptionFactory::OptionFactory(QWidget* parent)
    : QWidget(parent)
    , _american(new AmericanOptionFactory)
    , _assetOrNothing(new AssetOrNothingOptionFactory)
    , _cashOrNothing(new CashOrNothingOptionFactory)
    , _european(new EuropeanOptionFactory)
    , _asian(new IAsianOptionFactory)
    , _barrier(new IBarrierOptionFactory)
    , _lookback(new LookbackOptionFactory)
    , _content(new ComboBoxStackedWidget{ {
                { OptionFactory::AMERICAN,         _american },
                { OptionFactory::ASSET_OR_NOTHING, _assetOrNothing },
                { OptionFactory::CASH_OR_NOTHING, _cashOrNothing },
                { OptionFactory::EUROPEAN,        _european },
                { OptionFactory::ASIAN,           _asian },
                { OptionFactory::BARRIER,         _barrier },
                { OptionFactory::LOOKBACK,        _lookback }
              } })
{
    QBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(_content);

    connect(_content, SIGNAL(currentSelectionChanged(const QString&)), 
            this,     SLOT(changeCurrentOptionStyle(const QString&)));
}

OptionFactory::~OptionFactory()
{
}

QString OptionFactory::getCurrentSelection() const
{
    return _content->getCurrentSelection();
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
LookbackOption* OptionFactory::buildOption<LookbackOption>() const
{
    return _lookback->buildOption();
}

void OptionFactory::changeCurrentOptionStyle(const QString& text)
{
    emit(currentOptionStyleChanged(text));
}
