QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += path/to/qcustomplot

SOURCES += \
    ../help/calculate.c \
    ../help/credit_calc.c \
    ../help/divider.c \
    ../help/shunting_yard.c \
    ../help/stack.c \
    ../help/validation.c \
    ../smart_calc.c \
    qcustomplot.cpp \
    credit.cpp \
    graph.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../help/header/calculate.h \
    ../help/header/credit_calc.h \
    ../help/header/divider.h \
    ../help/header/shunting_yard.h \
    ../help/header/stack.h \
    ../help/header/validation.h \
    ../smart_calc.h \
    qcustomplot.h \
    credit.h \
    graph.h \
    mainwindow.h

FORMS += \
    credit.ui \
    graph.ui \
    mainwindow.ui

ICON = "icon/icons.icns"

DISTFILES += \
    icon/icons.icns

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
