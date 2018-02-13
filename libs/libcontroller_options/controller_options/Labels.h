#ifndef LABELS_h
#define LABELS_h

#include <string>


struct Labels
{
    struct Options
    {
        static const std::string AMERICAN;
        static const std::string ASIAN;
        static const std::string ASSET_OR_NOTHING;
        static const std::string BARRIER;
        static const std::string CASH_OR_NOTHING;
        static const std::string EUROPEAN;
        static const std::string LOOKBACK;
	};

    struct Models
    {
        static const std::string BINOMIAL_TREE;
        static const std::string BLACK_SCHOLES;
        static const std::string BLACK_SCHOLES_MC;
	};
};

#endif // LABELS_h