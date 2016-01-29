QT += core
QT -= gui

TARGET = TestView
CONFIG += console
CONFIG -= app_bundle

INCLUDEPATH += ../

CONFIG(debug, debug|release) {
  LIBS += -L../wal/debug
} else {
  LIBS += -L../wal/release
}

LIBS += -lwal

TEMPLATE = app

SOURCES += main.cpp

