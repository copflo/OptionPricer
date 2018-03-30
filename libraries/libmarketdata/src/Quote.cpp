#include "Quote.h"


Quote::Quote(const std::string& stockExchange, double opening, double highest, double lowest, double closing, double adjClosing)
    : _stockExchange(stockExchange)
    , _opening(opening)
    , _highest(highest)
    , _lowest(lowest)
    , _closing(closing)
    , _adjClosing(adjClosing)
{
}

Quote::Quote(std::string&& stockExchange, double opening, double highest, double lowest, double closing, double adjClosing)
    : _stockExchange(stockExchange)
    , _opening(opening)
    , _highest(highest)
    , _lowest(lowest)
    , _closing(closing)
    , _adjClosing(adjClosing)
{
}

Quote::~Quote()
{
}
