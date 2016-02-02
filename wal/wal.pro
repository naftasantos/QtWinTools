#-------------------------------------------------
#
# Windows Access Layer
#
# This project will contain everything there is to
# access Windows' methods and types
#
#-------------------------------------------------

QT       -= gui

TARGET = wal
TEMPLATE = lib
CONFIG += staticlib

DEFINES += WAL_LIBRARY

LIBS += -lAdvapi32

INCLUDEPATH += ../

SOURCES += \
    translations/win2qt.cpp \
    translations/qt2win.cpp \
    registry/reg_key.cpp \
    api/advapi32.cpp \
    api/kernel32.cpp

HEADERS += \
    translations/win2qt.h \
    translations/qt2win.h \
    registry/reg_key.h \
    api/advapi32.h \
    api/iapi.h \
    api/kernel32.h
