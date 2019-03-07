#-------------------------------------------------
#
# Project created by QtCreator 2019-03-06T19:24:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameOfLife
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    src/cpp/gui/mainwindow.cpp \
    src/cpp/main.cpp \
    src/cpp/game/board.cpp \
    src/cpp/game/field.cpp \
    src/cpp/game/boardmanager.cpp \
    src/cpp/file/filemanager.cpp \
    src/cpp/file/boarddata.cpp

HEADERS += \
    src/cpp/gui/mainwindow.hpp \
    src/cpp/game/board.hpp \
    src/cpp/game/field.hpp \
    src/cpp/static/neighborhoodtype.hpp \
    src/cpp/game/boardmanager.hpp \
    src/cpp/file/filemanager.hpp \
    src/cpp/file/boarddata.hpp \
    src/cpp/static/boardsize.hpp

FORMS += \
    src/forms/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
