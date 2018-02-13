#include "options/BlackScholes.h"

#include "Factory.h"


template<>
template<class UI>
BlackScholes* Factory<BlackScholes>::build(const UI& ui)
{
    return new BlackScholes(ui.volatility());
}
