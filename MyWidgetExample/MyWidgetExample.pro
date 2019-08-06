#-------------------------------------------------
#
# Project created by QtCreator 2019-04-25T19:47:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyWidgetExample
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

CONFIG += c++17

SOURCES += \
        OptionsDialog/colourlisteditor.cpp \
        OptionsDialog/mydelegate.cpp \
        OptionsDialog/myoptionsdialog.cpp \
        OptionsDialog/mystandarditemmodel.cpp \
        arc.cpp \
        dial.cpp \
        main.cpp \
        mainwindow.cpp \
        scale.cpp \
        testwidget.cpp

HEADERS += \
        OptionsDialog/colourlisteditor.h \
        OptionsDialog/mydelegate.h \
        OptionsDialog/myoptionsdialog.h \
        OptionsDialog/mystandarditemmodel.h \
        arc.h \
        arcpointf.h \
        dial.h \
        mainwindow.h \
        scale.h \
        square.h \
        testwidget.h

FORMS += \
        OptionsDialog/myoptionsdialog.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Data/build-Data-Desktop_Qt_5_12_3_GCC_64bit-Debug/release/ -lData
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Data/build-Data-Desktop_Qt_5_12_3_GCC_64bit-Debug/debug/ -lData
else:unix: LIBS += -L$$PWD/../Data/build-Data-Desktop_Qt_5_12_3_GCC_64bit-Debug/ -lData

INCLUDEPATH += $$PWD/../Data
DEPENDPATH += $$PWD/../Data

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../Data/build-Data-Desktop_Qt_5_12_3_GCC_64bit-Debug/release/libData.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../Data/build-Data-Desktop_Qt_5_12_3_GCC_64bit-Debug/debug/libData.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../Data/build-Data-Desktop_Qt_5_12_3_GCC_64bit-Debug/release/Data.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../Data/build-Data-Desktop_Qt_5_12_3_GCC_64bit-Debug/debug/Data.lib
else:unix: PRE_TARGETDEPS += $$PWD/../Data/build-Data-Desktop_Qt_5_12_3_GCC_64bit-Debug/libData.a
