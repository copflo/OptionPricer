cmake_minimum_required(VERSION 3.1.0)

project(pricer)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

set(SRC view-options/AmericanOptionFactory.cpp
        view-options/AmericanOptionFactory.h
        view-options/AssetOrNothingOptionFactory.cpp
        view-options/AssetOrNothingOptionFactory.h
        view-options/BaseOptionWidget.cpp
        view-options/BaseOptionWidget.h
        view-options/BinomialTreeFactory.cpp
        view-options/BinomialTreeFactory.h
        view-options/BlackScholesFactory.cpp
        view-options/BlackScholesFactory.h
        view-options/BlackScholesMonteCarloFactory.cpp
        view-options/BlackScholesMonteCarloFactory.h
        view-options/CashOrNothingOptionFactory.cpp
        view-options/CashOrNothingOptionFactory.h
        view-options/EuropeanOptionFactory.cpp
        view-options/EuropeanOptionFactory.h
        view-options/FrameContainer.cpp
        view-options/FrameContainer.h
        view-options/IAsianOptionFactory.cpp
        view-options/IAsianOptionFactory.h
        view-options/IBarrierOptionFactory.cpp
        view-options/IBarrierOptionFactory.h
        view-options/LookbackOptionFactory.cpp
        view-options/LookbackOptionFactory.h
        view-options/marketwidget.cpp
        view-options/marketwidget.h
        view-options/maturitywidget.cpp
        view-options/maturitywidget.h
        view-options/ModelFactory.cpp
        view-options/ModelFactory.h
        view-options/optionalstrikewidget.cpp
        view-options/optionalstrikewidget.h
        view-options/OptionFactory.cpp
        view-options/OptionFactory.h
        view-options/optionnaturewidget.cpp
        view-options/optionnaturewidget.h
        view-options/optionwindow.cpp
        view-options/optionwindow.h
        view-options/pathdependentoptionwidget.cpp
        view-options/pathdependentoptionwidget.h
        view-options/pathindependentoptionwidget.cpp
        view-options/pathindependentoptionwidget.h
        view-options/pricerview.cpp
        view-options/pricerview.h
        view-options/strikewidget.cpp
        view-options/strikewidget.h
        view-options/UnderlyingWidget.cpp
        view-options/UnderlyingWidget.h
        view-options/volatilitywidget.cpp
        view-options/volatilitywidget.h)

# Tell CMake to create the executable
add_executable(pricer WIN32 main.cpp ${SRC})
include_directories(../../include)
# Use the Widgets module from Qt5 with options lib.
target_link_libraries(pricer Qt5::Widgets options)
