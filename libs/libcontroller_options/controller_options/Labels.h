#ifndef LABELS_h
#define LABELS_h

#include <string>


template<class Str>
struct Labels
{
    struct Options
    {
        static const Str AMERICAN;
        static const Str ASIAN;
        static const Str ASSET_OR_NOTHING;
        static const Str BARRIER;
        static const Str CASH_OR_NOTHING;
        static const Str EUROPEAN;
        static const Str LOOKBACK;
	};

    struct Models
    {
        static const Str BINOMIAL_TREE;
        static const Str BLACK_SCHOLES;
        static const Str BLACK_SCHOLES_MC;
	};
};


template<class Str>
const Str Labels<Str>::Options::AMERICAN("American");
template<class Str>
const Str Labels<Str>::Options::ASIAN("Asian");
template<class Str>
const Str Labels<Str>::Options::ASSET_OR_NOTHING("Asset or nothing");
template<class Str>
const Str Labels<Str>::Options::BARRIER("Barrier");
template<class Str>
const Str Labels<Str>::Options::CASH_OR_NOTHING("Cash or nothing");
template<class Str>
const Str Labels<Str>::Options::EUROPEAN("European");
template<class Str>
const Str Labels<Str>::Options::LOOKBACK("Lookback");

template<class Str>
const Str Labels<Str>::Models::BINOMIAL_TREE("Binomial tree");
template<class Str>
const Str Labels<Str>::Models::BLACK_SCHOLES("Black Scholes");
template<class Str>
const Str Labels<Str>::Models::BLACK_SCHOLES_MC("Black Scholes - Monte Carlo");


#endif // LABELS_h