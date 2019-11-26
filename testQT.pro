QT += core gui network widgets
CONFIG += c++11
QT_CONFIG -= no-pkg-config
QMAKE_LFLAGS += -no-pie
TARGET = testQT
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
        $$PWD/main.cpp \
        $$PWD/testqt.cpp \
        AddonFridge.cpp \
        FridgeState.cpp \
        MyProcess.cpp \
        NFC/pmtreader.cpp \
        Pathes.cpp \
        files.cpp \
        server.cpp

HEADERS += \
        AddonfFridge.hh \
        FridgeState.h \
        MyProcess.hh \
        NFC/pmtreader.hh \
        Pathes.h \
        files.hh \
        server.hh \
        testqt.h
FORMS += \
        testqt.ui

RESOURCES += \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -L$$PWD/NFC/ -lpmtcatstatic

INCLUDEPATH += $$PWD/NFC
DEPENDPATH += $$PWD/NFC

unix:!macx: PRE_TARGETDEPS += $$PWD/NFC/libpmtcatstatic.a
