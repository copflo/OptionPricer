#include "BlackScholesSpot.h"


BlackScholesSpot::BlackScholesSpot(double riskfreeRate, int period, const Volatility& vol)
    : _riskfreeRate(riskfreeRate)
    , _period(period)
    , _vol(vol)
{
}

BlackScholesSpot::~BlackScholesSpot()
{
}

double BlackScholesSpot::riskfreeRate() const
{
    return _riskfreeRate;
}

int BlackScholesSpot::period() const
{
    return _period;
}

const Volatility& BlackScholesSpot::volatility() const
{
    return _vol;
}

double BlackScholesSpot::operator()(double initSpot)
{
    const double T = static_cast<double>(_period) / _vol.period();
    const double drift = (_riskfreeRate - (pow(_vol.value(), 2) / 2));
    const double brownian_move = exp(_vol.value(_period) * _brownian());

    return initSpot * exp(drift * T) * brownian_move;
}

