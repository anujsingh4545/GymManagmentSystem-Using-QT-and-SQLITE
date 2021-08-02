QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    checkhistory.cpp \
    home.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    moreabout.cpp \
    register.cpp \
    reset.cpp \
    signupdialog.cpp \
    terms.cpp

HEADERS += \
    checkhistory.h \
    home.h \
    logindialog.h \
    mainwindow.h \
    moreabout.h \
    register.h \
    reset.h \
    signupdialog.h \
    terms.h

FORMS += \
    checkhistory.ui \
    home.ui \
    logindialog.ui \
    mainwindow.ui \
    moreabout.ui \
    register.ui \
    reset.ui \
    signupdialog.ui \
    terms.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagesrc.qrc
