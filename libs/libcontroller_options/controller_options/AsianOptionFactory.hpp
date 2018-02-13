#include "options/AsianOption.h"

#include "Factory.h"


template<>
template<class UI>
IAsianOption* Factory<IAsianOption>::build(const UI& ui)
{
    OptionNature* nature = ui.nature();
    const size_t maturity = ui.maturity();
    const size_t obsFreq = ui.observationFrequency();

    if(ui.strikeIsFloating()) {
        if(ui.optionIsArithmetic()) {
            return new AsianOption<ArithmeticAverage, FloatingStrike>(nature,
                                                                      maturity,
                                                                      obsFreq);
        }
        return new AsianOption<GeometricAverage, FloatingStrike>(nature,
                                                                 maturity,
                                                                 obsFreq);
    }

    const double strike = ui.strike();
    if(ui.optionIsArithmetic()) {
        return new AsianOption<ArithmeticAverage, FixedStrike>(nature,
                                                               maturity,
                                                               obsFreq,
                                                               strike);
    }
    return new AsianOption<GeometricAverage, FixedStrike>(nature,
                                                          maturity,
                                                          obsFreq,
                                                          strike);
}
