#ifndef AsianOption_h
#define AsianOption_h

#include "ArithmeticAverage.h"
#include "GeometricAverage.h"
#include "FixedStrike.h"
#include "FloatingStrike.h"
#include "IAsianOption.h"

namespace {
    template<class Average>
    class BaseAsianOption
        : public IAsianOption
    {
    public:
        BaseAsianOption(Nature nature, int maturity, const int obsFreq)
            : IAsianOption(nature, maturity, obsFreq)
        {
        }

        virtual ~BaseAsianOption()
        {
        }

        virtual void print(std::ostream& os) const
        {
            Option::print(os);
            os << _avg.toString() << std::endl;
        }

    protected:
        Average _avg;
    };
}

template<class Average, class StrikeFloatingness>
class AsianOption;

template<class Average>
class AsianOption<Average, FixedStrike>
    : public BaseAsianOption<Average>
    , public FixedStrike
{
public:
    AsianOption(Nature nature, int maturity, int obsFreq, double strike)
        : BaseAsianOption<Average>(nature, maturity, obsFreq)
        , FixedStrike(strike)
    {
    }

    virtual ~AsianOption()
    {
    }

    virtual double payoff(const std::vector<double>& spot_path) const
    {
        return Option::payoff(_avg(spot_path), _strike);
    }

    virtual void print(std::ostream& os) const
    {
        BaseAsianOption<Average>::print(os);
        os << "Strike : " << _strike << std::endl;
    }
};


template<class Average>
class AsianOption<Average, FloatingStrike>
    : public BaseAsianOption<Average>
    , public FloatingStrike
{
public:
    AsianOption(Nature nature, int maturity, int obsFreq)
        : BaseAsianOption<Average>(nature, maturity, obsFreq)
    {
    }

    virtual ~AsianOption()
    {
    }

    virtual double payoff(const std::vector<double>& spot_path) const
    {
        return Option::payoff(spot_path.back(), strike(spot_path));
    }

protected:
    virtual double strike(const std::vector<double>& spot_path) const
    {
        return _avg(spot_path);
    }
};

#endif /* AsianOption_h */