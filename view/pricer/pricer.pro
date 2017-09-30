#-------------------------------------------------
#
# Project created by QtCreator 2017-09-16T22:59:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

CONFIG(debug, debug|release) {       # differencier les differents modes de compilation
    DESTDIR = build/debug            # repertoire ou placer l'executable
    TARGET = pricer-d                # nom du programme, je rajoute souvent -d pour distinguer le debug du release
    OBJECTS_DIR = build/debug/.obj   # on place les .o ici en debug
    MOC_DIR = build/debug/moc        # les.moc
    RCC_DIR = build/debug/rcc        # les .rcc
    UI_DIR = build/debug/ui          # les .ui
} else {
    DESTDIR = ../../bin              # repertoire ou placer l'executable
    TARGET = pricer                  # ici c'est en release
    OBJECTS_DIR = build/release/.obj # .o
    MOC_DIR = build/release/moc      # .moc
    RCC_DIR = build/release/rcc      # .rcc
    UI_DIR = build/release/ui        # .ui
}

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
    view-options/AmericanOptionFactory.cpp \
    view-options/AssetOrNothingOptionFactory.cpp \
    view-options/BaseOptionWidget.cpp \
    view-options/BlackScholesFactory.cpp \
    view-options/BlackScholesMonteCarloFactory.cpp \
    view-options/CashOrNothingOptionFactory.cpp \
    view-options/CoxRossRubinsteinFactory.cpp \
    view-options/EuropeanOptionFactory.cpp \
    view-options/FrameContainer.cpp \
    view-options/IAsianOptionFactory.cpp \
    view-options/IBarrierOptionFactory.cpp \
    view-options/LookbackOptionFactory.cpp \
    view-options/marketwidget.cpp \
    view-options/ModelFactory.cpp \
    view-options/optionalstrikewidget.cpp \
    view-options/OptionFactory.cpp \
    view-options/optionwindow.cpp \
    view-options/pathdependentoptionwidget.cpp \
    view-options/pathindependentoptionwidget.cpp \
    view-options/pricerview.cpp \
    view-options/strikewidget.cpp \
    view-options/UnderlyingWidget.cpp \
    view-options/volatilitywidget.cpp \
    main.cpp

HEADERS += \
    view-options/AmericanOptionFactory.h \
    view-options/AssetOrNothingOptionFactory.h \
    view-options/BaseOptionWidget.h \
    view-options/BlackScholesFactory.h \
    view-options/BlackScholesMonteCarloFactory.h \
    view-options/CashOrNothingOptionFactory.h \
    view-options/CoxRossRubinsteinFactory.h \
    view-options/EuropeanOptionFactory.h \
    view-options/FrameContainer.h \
    view-options/IAsianOptionFactory.h \
    view-options/IBarrierOptionFactory.h \
    view-options/LookbackOptionFactory.h \
    view-options/marketwidget.h \
    view-options/ModelFactory.h \
    view-options/optionalstrikewidget.h \
    view-options/OptionFactory.h \
    view-options/optionwindow.h \
    view-options/pathdependentoptionwidget.h \
    view-options/pathindependentoptionwidget.h \
    view-options/pricerview.h \
    view-options/strikewidget.h \
    view-options/UnderlyingWidget.h \
    view-options/volatilitywidget.h

unix:macx: LIBS += -L../../lib/ -lOptions
windows: LIBS += -L../../bin -lOptions

INCLUDEPATH += ../../include
DEPENDPATH += ../../include

QMAKE_CXXFLAGS += -std=c++11
