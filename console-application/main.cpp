#include "BlackScholes.h"
#include "BlackScholesMontecarlo.h"
#include "NbObs.h"


int main(int argc, char** argv)
{
    const double risklessRate = 0.05;
    const double spot = 100.0;
    const Volatility vol(0.15, 365);

    std::cout << "Riskless rate: " << risklessRate << std::endl;
    std::cout << "Current stock price: " << spot << std::endl;
    std::cout << "Volatility of asset: " << vol << std::endl;
    std::cout << std::endl;

    EuropeanOption eu_call(Option::CALL, 90, 105.0);
    std::cout << eu_call << std::endl;

    BlackScholes bs(vol);
    std::cout << "Price by Black Scholes model: " << bs.price(risklessRate, spot, eu_call) << std::endl;

    BlackScholesMonteCarlo bsMc(vol, new NbObs(1000000));
    std::cout << "Price by Monte Carlo simulation of Black Scholes model: ";
    std::cout << bsMc.price(risklessRate, spot, eu_call) << std::endl;
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
