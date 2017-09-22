#-------------------------------------------------
#
# Project created by QtCreator 2017-09-16T22:59:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pricer
TEMPLATE = app

Release:DESTDIR = ../../bin

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    ../options/AmericanOptionFactory.cpp \
    ../options/AssetOrNothingOptionFactory.cpp \
    ../options/BaseOptionWidget.cpp \
    ../options/BlackScholesFactory.cpp \
    ../options/BlackScholesMonteCarloFactory.cpp \
    ../options/CashOrNothingOptionFactory.cpp \
    ../options/CoxRossRubinsteinFactory.cpp \
    ../options/EuropeanOptionFactory.cpp \
    ../options/FrameContainer.cpp \
    ../options/IAsianOptionFactory.cpp \
    ../options/IBarrierOptionFactory.cpp \
    ../options/LookbackOptionFactory.cpp \
    ../options/marketwidget.cpp \
    ../options/ModelFactory.cpp \
    ../options/optionalstrikewidget.cpp \
    ../options/OptionFactory.cpp \
    ../options/optionwindow.cpp \
    ../options/pathdependentoptionwidget.cpp \
    ../options/pathindependentoptionwidget.cpp \
    ../options/pricerview.cpp \
    ../options/strikewidget.cpp \
    ../options/UnderlyingWidget.cpp \
    ../options/volatilitywidget.cpp

HEADERS += \
    ../options/AmericanOptionFactory.h \
    ../options/AssetOrNothingOptionFactory.h \
    ../options/BaseOptionWidget.h \
    ../options/BlackScholesFactory.h \
    ../options/BlackScholesMonteCarloFactory.h \
    ../options/CashOrNothingOptionFactory.h \
    ../options/CoxRossRubinsteinFactory.h \
    ../options/EuropeanOptionFactory.h \
    ../options/FrameContainer.h \
    ../options/IAsianOptionFactory.h \
    ../options/IBarrierOptionFactory.h \
    ../options/LookbackOptionFactory.h \
    ../options/marketwidget.h \
    ../options/ModelFactory.h \
    ../options/optionalstrikewidget.h \
    ../options/OptionFactory.h \
    ../options/optionwindow.h \
    ../options/pathdependentoptionwidget.h \
    ../options/pathindependentoptionwidget.h \
    ../options/pricerview.h \
    ../options/strikewidget.h \
    ../options/UnderlyingWidget.h \
    ../options/volatilitywidget.h

unix:!macx: LIBS += -L../../lib/ -lOptions

INCLUDEPATH += ../../include
DEPENDPATH += ../../include
