cmake_minimum_required(VERSION 3.4.1)

project(pricer)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

set(SRC pricer/view-options/AsianOptionWidget.cpp
		pricer/view-options/AsianOptionWidget.h
		pricer/view-options/BarrierOptionWidget.cpp
		pricer/view-options/BarrierOptionWidget.h
		pricer/view-options/BaseOptionWidget.cpp
		pricer/view-options/BaseOptionWidget.h
		pricer/view-options/BinomialTreeWidget.cpp
		pricer/view-options/BinomialTreeWidget.h
		pricer/view-options/BlackScholesMonteCarloWidget.cpp
		pricer/view-options/BlackScholesMonteCarloWidget.h
		pricer/view-options/BlackScholesWidget.cpp
		pricer/view-options/BlackScholesWidget.h
		pricer/view-options/CashOrNothingOptionWidget.cpp
		pricer/view-options/CashOrNothingOptionWidget.h
		pricer/view-options/LookbackOptionWidget.cpp
		pricer/view-options/LookbackOptionWidget.h
		pricer/view-options/marketwidget.cpp
		pricer/view-options/marketwidget.h
		pricer/view-options/maturitywidget.cpp
		pricer/view-options/maturitywidget.h
		pricer/view-options/ModelFactoryWidget.cpp
		pricer/view-options/ModelFactoryWidget.h
		pricer/view-options/OptController.cpp
		pricer/view-options/OptController.h
		pricer/view-options/optionalstrikewidget.cpp
		pricer/view-options/optionalstrikewidget.h
		pricer/view-options/OptionFactoryWidget.cpp
		pricer/view-options/OptionFactoryWidget.h
		pricer/view-options/optionnaturewidget.cpp
		pricer/view-options/optionnaturewidget.h
		pricer/view-options/optionwindow.cpp
		pricer/view-options/optionwindow.h
		pricer/view-options/pathdependentoptionwidget.cpp
		pricer/view-options/pathdependentoptionwidget.h
		pricer/view-options/PathIndependentOptionWidget.cpp
		pricer/view-options/PathIndependentOptionWidget.h
		pricer/view-options/strikewidget.cpp
		pricer/view-options/strikewidget.h
		pricer/view-options/UnderlyingWidget.cpp
		pricer/view-options/UnderlyingWidget.h
		pricer/view-options/volatilitywidget.cpp
		pricer/view-options/volatilitywidget.h)

# Tell CMake to create the executable
add_executable(pricer ./pricer/main.cpp ${SRC})
target_include_directories(pricer PRIVATE "../libs/liboptions" "../libraries/libcontroller_options")
# Use the Widgets module from Qt5 with options lib.
target_link_libraries(pricer Qt5::Widgets options controller_options)
