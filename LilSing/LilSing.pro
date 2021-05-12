QT       += core gui multimedia multimediawidgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    model/recorder.cpp \
    model/sqlhandler.cpp \
    model/videoplayer.cpp \
    view/mainwindow.cpp \
    model/model.cpp \
    model/musicplayer.cpp

HEADERS += \
    model/recorder.h \
    model/sqlhandler.h \
    model/videoplayer.h \
    view/mainwindow.h \
    model/model.h \
    model/musicplayer.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
