#ifndef QUOTE_H
#define QUOTE_H

#include <string>


struct Quote
{
    Quote (const std::string& stockExchange,
           double opening,
           double highest,
           double lowest,
           double closing,
           double adjClosing);
    Quote (std::string&& stockExchange,
           double opening,
           double highest,
           double lowest,
           double closing,
           double adjClosing);
    ~Quote();

    const std::string _stockExchange;
    const double      _opening;
    const double      _highest;
    const double      _lowest;
    const double      _closing;
    const double      _adjClosing;
};


#endif // QUOTE_H
