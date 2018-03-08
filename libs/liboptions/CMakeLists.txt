cmake_minimum_required(VERSION 3.4.1)

project(liboptions)

set(HEADERS options/AccuracyConfidence.h
            options/AmericanOption.h
            options/ArithmeticAverage.h
            options/AsianOption.h
            options/AssetOrNothingOption.h
            options/BarrierOption.h
            options/BinomialTree.h
            options/BlackScholes.h
            options/BlackScholesGen.h
            options/BlackScholesMontecarlo.h
            options/BS_StockPriceGen.h
            options/BS_StockPricePathGen.h
			options/BrownianMotionGen.h
            options/Call.h
            options/CashOrNothingOption.h
            options/DigitalOption.h
            options/Down.h
            options/EuropeanOption.h
            options/FixedStrike.h
            options/FloatingStrike.h
            options/GaussianRandomVariable.h
            options/GeometricAverage.h
			options/greeks.h
            options/IAsianOption.h
            options/IBarrierOption.h
            options/ILookbackOption.h
            options/KnockIn.h
            options/KnockOut.h
            options/LookbackOption.h
            options/math_functions.h
			options/MC_Simulation.h
            options/NbObs.h
            options/Option.h
            options/OptionNature.h
            options/PathDependentOption.h
            options/PathIndependentOption.h
            options/Put.h
			options/SimulationRunner.h
            options/StopSimulation.h
            options/TimeLimit.h
            options/Up.h
            options/VanillaOption.h
            options/Volatility.h)


set(SRC src/AccuracyConfidence.cpp
        src/AmericanOption.cpp
        src/ArithmeticAverage.cpp
        src/AssetOrNothingOption.cpp
        src/BinomialTree.cpp
        src/BlackScholes.cpp
        src/BlackScholesGen.cpp
        src/BlackScholesMontecarlo.cpp
        src/BS_StockPriceGen.cpp
        src/BS_StockPricePathGen.cpp
        src/BrownianMotionGen.cpp
        src/Call.cpp
        src/CashOrNothingOption.cpp
        src/DigitalOption.cpp
        src/Down.cpp
        src/EuropeanOption.cpp
        src/FixedStrike.cpp
        src/FloatingStrike.cpp
        src/GaussianRandomVariable.cpp
        src/GeometricAverage.cpp
		src/greeks.cpp
        src/IAsianOption.cpp
        src/IBarrierOption.cpp
        src/ILookbackOption.cpp
        src/KnockIn.cpp
        src/KnockOut.cpp
        src/LookbackOption.cpp
        src/math_functions.cpp
		src/MC_Simulation.cpp
        src/NbObs.cpp
        src/Option.cpp
        src/PathDependentOption.cpp
        src/PathIndependentOption.cpp
        src/Put.cpp
		src/SimulationRunner.cpp
        src/StopSimulation.cpp
        src/TimeLimit.cpp
        src/Up.cpp
        src/VanillaOption.cpp
        src/Volatility.cpp)

add_library(options SHARED ${HEADERS} ${SRC})
target_include_directories(options PRIVATE "options")
