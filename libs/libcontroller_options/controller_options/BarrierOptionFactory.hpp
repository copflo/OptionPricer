#ifndef BARRIEROPTIONFACTORY_H
#define BARRIEROPTIONFACTORY_H

#include "options/BarrierOption.h"

#include "Factory.h"


template<>
template<class UI>
IBarrierOption* Factory<IBarrierOption>::build(const UI& ui)
{
    OptionNature* nature = ui.nature();
    const size_t maturity = ui.maturity();
    const size_t obsFreq = ui.observationFrequency();
    const double strike = ui.strike();
	const double barrier = ui.barrier();

    if(ui.barrierIsUp()) {
        if(ui.barrierIsIn()) {
            return new BarrierOption<Up, KnockIn>(nature,
                                                  maturity,
                                                  obsFreq,
                                                  strike,
                                                  barrier);
        }
        return new BarrierOption<Up, KnockOut>(nature,
                                               maturity,
                                               obsFreq,
                                               strike,
                                               barrier);
    }

    if(ui.barrierIsIn()) {
        return new BarrierOption<Down, KnockIn>(nature,
                                                maturity,
                                                obsFreq,
                                                strike,
                                                barrier);
    }
    return new BarrierOption<Down, KnockOut>(nature,
                                             maturity,
                                             obsFreq,
                                             strike,
                                             barrier);
}


#endif // BARRIEROPTIONFACTORY_H
