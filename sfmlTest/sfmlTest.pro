TEMPLATE = app
CONFIG += console c++11
CONFIG += C++11
QMAKE_CXXFLAGS += -std=c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp


LIBS += -L"/home/david/SFML-2.4.2/lib"
LIBS += -L"/home/david/SFML-2.4.2/bin"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window #ORDER MATTERS!
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH += "/home/david/SFML-2.4.2/include"
DEPENDPATH += "/home/david/SFML-2.4.2/include"
