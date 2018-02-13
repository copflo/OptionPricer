#include "OptionFactory.h"


const std::string& OptionFactory::AMERICAN()
{
    static const std::string _amer("American");
    return _amer;
}

const std::string& OptionFactory::ASIAN()
{
    static const std::string _asian("Asian");
    return _asian;
}

const std::string& OptionFactory::ASSET_OR_NOTHING()
{
    static const std::string _asset_or_nothing("Asset or nothing");
    return _asset_or_nothing;
}

const std::string& OptionFactory::BARRIER()
{
    static const std::string _barrier("Barrier");
    return _barrier;
}

const std::string& OptionFactory::CASH_OR_NOTHING()
{
    static const std::string _cash_or_nothing("Cash or nothing");
    return _cash_or_nothing;
}

const std::string& OptionFactory::EUROPEAN()
{
    static const std::string _eu("European");
    return _eu;
}

const std::string& OptionFactory::LOOKBACK()
{
    static const std::string _lookback("Lookback");
    return _lookback;
}
