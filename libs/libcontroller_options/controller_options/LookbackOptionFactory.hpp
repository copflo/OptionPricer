#include "options/LookbackOption.h"

#include "Factory.h"


template<>
template<class UI>
ILookbackOption* Factory<ILookbackOption>::build(const UI& ui)
{
    OptionNature* nature = ui.nature();
    const size_t maturity = ui.maturity();
    const size_t obsFreq = ui.observationFrequency();

    if(ui.strikeIsFloating()) {
        return new LookbackOption<FloatingStrike>(nature, maturity, obsFreq);
    }
    return new LookbackOption<FixedStrike>(nature, maturity, obsFreq, ui.strike());
}
