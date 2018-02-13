cmake_minimum_required(VERSION 3.4.1)

project(libcontroller_options)

set(SRC controller_options/AController.h
        controller_options/AsianOptionFactory.hpp
        controller_options/BarrierOptionFactory.hpp
        controller_options/BinomialTreeFactory.hpp
        controller_options/BlackScholesFactory.hpp
        controller_options/BlackScholesMCFactory.hpp
        controller_options/CashOrNothingOptionFactory.hpp
        controller_options/Controller.h
        controller_options/Factory.h
        controller_options/Labels.h
        controller_options/LookbackOptionFactory.hpp
        controller_options/PathIndependentOptionFactory.hpp
		controller_options/Pricer.h
        src/AController.cpp
        src/Labels.cpp)

add_library(controller_options STATIC ${SRC})
target_include_directories(controller_options PRIVATE "controller_options" "../liboptions")
