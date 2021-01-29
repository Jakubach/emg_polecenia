TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        button.cpp \
        case.cpp \
        caseabstract.cpp \
        customrectangleshape.cpp \
        customsprite.cpp \
        main.cpp \
        scena.cpp \
        scenaabstract.cpp \
        uicommad.cpp \
        uicommadsetcolor.cpp

HEADERS += \
    button.h \
    case.h \
    caseabstract.h \
    customrectangleshape.h \
    customsprite.h \
    scena.h \
    scenaabstract.h \
    uicommad.h \
    uicommadsetcolor.h

LIBS += -lOpenGL32 -lglu32
INCLUDEPATH += "C:/SFML-2.5.1/include"
LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}
