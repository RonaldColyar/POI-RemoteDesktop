QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    confirmbreachpopup.cpp \
    main.cpp \
    main_functionality.cpp \
    mainwindow.cpp \
    newentrypopup.cpp \
    newpersonpopup.cpp

HEADERS += \
    confirmbreachpopup.h \
    main_functionality.h \
    mainwindow.h \
    newentrypopup.h \
    newpersonpopup.h

FORMS += \
    confirmbreachpopup.ui \
    mainwindow.ui \
    newentrypopup.ui \
    newpersonpopup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
