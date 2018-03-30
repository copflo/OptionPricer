cmake_minimum_required(VERSION 3.4.1)

project(libcontroller_options)

set(SRC controller_options/AsianOptionFactory.hpp
        controller_options/BarrierOptionFactory.hpp
        controller_options/BinomialTreeFactory.hpp
        controller_options/BlackScholesFactory.hpp
        controller_options/BlackScholesMCFactory.hpp
        controller_options/CashOrNothingOptionFactory.hpp
        controller_options/Controller.h
        controller_options/Factory.h
        controller_options/Labels.h
        controller_options/LookbackOptionFactory.hpp
        controller_options/ModelsCatalog.h
        controller_options/PathIndependentOptionFactory.hpp
	controller_options/Pricer.h
        controller_options/PricingMapBuilder.h)

add_library(controller_options INTERFACE)
target_include_directories(controller_options INTERFACE "controller_options" "../liboptions")
