cmake_minimum_required(VERSION 3.4.1)

project(liboptions)

set(HEADERS ../../include/options/AccuracyConfidence.h
            ../../include/options/AmericanOption.h
            ../../include/options/ArithmeticAverage.h
            ../../include/options/AsianOption.h
            ../../include/options/AssetOrNothingOption.h
            ../../include/options/BarrierOption.h
            ../../include/options/BinomialTree.h
            ../../include/options/BlackScholes.h
            ../../include/options/BlackScholesGen.h
            ../../include/options/BlackScholesMontecarlo.h
            ../../include/options/BlackScholesSpot.h
            ../../include/options/BrownianMotionGen.h
            ../../include/options/Call.h
            ../../include/options/CashOrNothingOption.h
            ../../include/options/DigitalOption.h
            ../../include/options/Down.h
            ../../include/options/EuropeanOption.h
            ../../include/options/FixedStrike.h
            ../../include/options/FloatingStrike.h
            ../../include/options/GaussianRandomVariable.h
            ../../include/options/GeometricAverage.h
            ../../include/options/IAsianOption.h
            ../../include/options/IBarrierOption.h
            ../../include/options/ILookbackOption.h
            ../../include/options/KnockIn.h
            ../../include/options/KnockOut.h
            ../../include/options/LookbackOption.h
            ../../include/options/math_functions.h
            ../../include/options/MonteCarloSimulation.h
            ../../include/options/NbObs.h
            ../../include/options/NormalDistributionSimulator.h
            ../../include/options/Option.h
            ../../include/options/OptionNature.h
            ../../include/options/OptionSensitivity.h
            ../../include/options/PathDependentOption.h
            ../../include/options/PathGenerator.h
            ../../include/options/PathIndependentOption.h
            ../../include/options/Put.h
            ../../include/options/RunningStats.h
            ../../include/options/StopSimulation.h
            ../../include/options/TimeLimit.h
            ../../include/options/Up.h
            ../../include/options/VanillaOption.h
            ../../include/options/Volatility.h)


set(SRC AccuracyConfidence.cpp
        AmericanOption.cpp
        ArithmeticAverage.cpp
        AssetOrNothingOption.cpp
        BinomialTree.cpp
        BlackScholes.cpp
        BlackScholesGen.cpp
        BlackScholesMontecarlo.cpp
        BlackScholesSpot.cpp
        BrownianMotionGen.cpp
        Call.cpp
        CashOrNothingOption.cpp
        DigitalOption.cpp
        Down.cpp
        EuropeanOption.cpp
        FixedStrike.cpp
        FloatingStrike.cpp
        GaussianRandomVariable.cpp
        GeometricAverage.cpp
        IAsianOption.cpp
        IBarrierOption.cpp
        ILookbackOption.cpp
        KnockIn.cpp
        KnockOut.cpp
        LookbackOption.cpp
        math_functions.cpp
        MonteCarloSimulation.cpp
        NbObs.cpp
        Option.cpp
        OptionSensitivity.cpp
        PathDependentOption.cpp
        PathGenerator.cpp
        PathIndependentOption.cpp
        Put.cpp
        RunningStats.cpp
        StopSimulation.cpp
        TimeLimit.cpp
        Up.cpp
        VanillaOption.cpp
        Volatility.cpp)

include_directories(../../include ../../include/options)
add_library(options SHARED ${HEADERS} ${SRC})
