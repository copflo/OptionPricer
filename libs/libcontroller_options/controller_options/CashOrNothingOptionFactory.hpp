#include "options/CashOrNothingOption.h"

#include "Factory.h"


template<>
template<class UI>
CashOrNothingOption* Factory<CashOrNothingOption>::build(const UI& ui)
{
    return new CashOrNothingOption(ui.nature(),
                                   ui.maturity(),
                                   ui.strike(),
                                   ui.rebate());
}
