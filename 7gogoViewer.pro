TEMPLATE = app
TARGET = 7gogoViewer

QT += core gui network multimedia multimediawidgets

CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets

SOURCES += \
    main.cpp \
    messagebox.cpp \
    window.cpp \
    contentbox.cpp \
    messageboxtype1.cpp \
    messageboxtype2.cpp \
    imagelabel.cpp \
    image.cpp \
    messageboxtype3.cpp \
    messageboxtype4.cpp \
    messageboxtype5.cpp \
    messageboxtype7.cpp \
    messageboxtype6.cpp \
    messageboxtype8.cpp

HEADERS += \
    messagebox.h \
    window.h \
    contentbox.h \
    messageboxtype1.h \
    messageboxtype2.h \
    imagelabel.h \
    image.h \
    messageboxtype3.h \
    messageboxtype4.h \
    messageboxtype5.h \
    messageboxtype7.h \
    messageboxtype6.h \
    messageboxtype8.h

DISTFILES += \
    json.txt
