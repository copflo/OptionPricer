#include <cstdio>

#include "options/BlackScholes.h"
#include "options/BlackScholesMontecarlo.h"
#include "options/BlackScholesFDM.h"


int main(int argc, char** argv)
{
    const double r = 0.05;
    const double s0 = 100.0;
    const Volatility vol(0.15, 365);

    std::cout << "Riskless rate: " << r << std::endl;
    std::cout << "Current stock price: " << s0 << std::endl;
    std::cout << "Volatility of asset: " << vol << std::endl;
    std::cout << std::endl;

    EuropeanOption eu_call(new Call, 90, 105.0);
    std::cout << eu_call << std::endl;

    BlackScholes bs(vol);
    std::cout << "Price by Black Scholes model: " << bs.price(r, s0, eu_call) << std::endl;

    BlackScholesMonteCarlo bsMc(vol, new NbObs(1000000));
    std::cout << "Price by Monte Carlo simulation of Black Scholes model: ";
    std::cout << bsMc.price(r, s0, eu_call) << std::endl;
    std::cout << std::endl;

    BlackScholesFDM bsFdm(vol, 20, 360);
    std::cout << "Price surface by finite difference method for Black Scholes PDE:" << std::endl;
    //bsFdm.writePriceSurface(r, eu_call, std::cout);
    FILE* gnuplot = NULL;
    const char* gnuplot_cmd = "gnuplot -persist";
    #if defined _MSC_VER
        gnuplot = _popen(gnuplot_cmd, "w");
    #else
        gnuplot = popen(gnuplot_cmd, "w");
     #endif
    fprintf(gnuplot, "set hidden3d\n");
    fprintf(gnuplot, "set pm3d\n");
    fprintf(gnuplot, "set palette rgbformulae 33, 13, 10\n");
    fprintf(gnuplot, "set ticslevel 0\n");
    fprintf(gnuplot, "set title \"Price surface(t, S)\"\n");
    fprintf(gnuplot, "set xlabel \"t\"\n");
    fprintf(gnuplot, "set ylabel \"S\"\n");
    fprintf(gnuplot, "set zlabel \"P(t, S)\"\n");
    fprintf(gnuplot, "splot '-' u 1:2:3 with lines\n");
    bsFdm.writePriceSurface(r, eu_call, *gnuplot);
    fprintf(gnuplot, "e\n");
    #if defined _MSC_VER
        _pclose(gnuplot);
        system("pause");
    #else
        pclose(gnuplot);
    #endif

    return EXIT_SUCCESS;
}
