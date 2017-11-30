#ifndef AsianOption_h
#define AsianOption_h

#include "ArithmeticAverage.h"
#include "GeometricAverage.h"
#include "FixedStrike.h"
#include "FloatingStrike.h"
#include "IAsianOption.h"


template<class Average, class StrikeFloatingness>
class AsianOption;


template<class Average>
class AsianOption<Average, FixedStrike>
    : public IAsianOption
    , public FixedStrike
{
public:
            AsianOption (OptionNature* nature, size_t maturity, size_t obsFreq, double strike);
    virtual ~AsianOption();

    virtual double payoff(const std::vector<double>& spot_path) const;
    virtual void   print (std::ostream& os) const;
};


template<class Average>
class AsianOption<Average, FloatingStrike>
    : public IAsianOption
    , public FloatingStrike
{
public:
            AsianOption (OptionNature* nature, size_t maturity, size_t obsFreq);
    virtual ~AsianOption();

    virtual double payoff(const std::vector<double>& spot_path) const;
    virtual void   print (std::ostream& os)                     const;

protected:
    virtual double strike(const std::vector<double>& spot_path) const;
};


template<class Average>
AsianOption<Average, FixedStrike>::AsianOption(OptionNature* nature, int maturity, int obsFreq, double strike)
    : IAsianOption(nature, maturity, obsFreq)
    , FixedStrike(strike)
{
}

template<class Average>
AsianOption<Average, FixedStrike>::~AsianOption()
{
}

template<class Average>
double AsianOption<Average, FixedStrike>::payoff(const std::vector<double>& spot_path) const
{
    return _nature->payoff(Average::average(spot_path), _strike);
}

template<class Average>
void AsianOption<Average, FixedStrike>::print(std::ostream& os) const
{
    Option::print(os);
    os << Average::toString() << std::endl;
    os << "Strike : " << _strike << std::endl;
}


template<class Average>
AsianOption<Average, FloatingStrike>::AsianOption(OptionNature* nature, size_t maturity, size_t obsFreq)
    : IAsianOption(nature, maturity, obsFreq)
{
}

template<class Average>
AsianOption<Average, FloatingStrike>::~AsianOption()
{
}

template<class Average>
double AsianOption<Average, FloatingStrike>::payoff(const std::vector<double>& spot_path) const
{
    return _nature->payoff(spot_path.back(), strike(spot_path));
}

template<class Average>
void AsianOption<Average, FloatingStrike>::print(std::ostream& os) const
{
    Option::print(os);
    os << Average::toString() << std::endl;
}

template<class Average>
double AsianOption<Average, FloatingStrike>::strike(const std::vector<double>& spot_path) const
{
    return Average::average(spot_path);
}


#endif // AsianOption_h
