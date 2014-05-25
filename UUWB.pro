#-------------------------------------------------
#
# Project created by QtCreator 2014-04-28T12:48:16
#
#-------------------------------------------------

QT += core gui network webkitwidgets
#--------------------------------------------------
#sudo apt-get install libgstreamer1.0-dev
#sudo apt-get install libgstreamer0.10-dev
#sudo apt-get install libgstreamer-plugins-base1.0-dev
#sudo apt-get install libgstreamer-plugins-base0.10-dev
#----------------------------------------------------
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UUWB
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sdk/net/NetWorkManager.cpp \
    sdk/keep/AccessTokenKeeper.cpp \
    sdk/WeiboParameters.cpp \
    sdk/api/WeiBoAPI.cpp \
    sdk/WeiBoAction.cpp \
    sdk/api/UserAPI.cpp \
    sdk/WeiBo.cpp \
    userpage.cpp

HEADERS  += mainwindow.h \
    sdk/WeiBoAction.h \
    globaldata.h \
    sdk/WeiboParameters.h \
    sdk/net/NetWorkManager.h \
    sdk/api/WeiBoAPI.h \
    sdk/api/UserAPI.h \
    sdk/WeiBo.h \
    sdk/keep/AccessTokenKeeper.h \
    userpage.h

FORMS    += mainwindow.ui \
    userpage.ui
