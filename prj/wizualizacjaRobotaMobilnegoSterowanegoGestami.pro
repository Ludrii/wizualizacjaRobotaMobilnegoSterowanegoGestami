QT       += \
    core gui \
    printsupport \
    serialport \
    widgets

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/odbior.cpp \
    src/qcustomplot.cpp \
    src/secondwindow.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    inc/mainwindow.hh \
    inc/odbior.hh \
    inc/qcustomplot.hh \
    inc/secondwindow.hh

FORMS += \
    ui/secondwindow.ui \
    ui/mainwindow.ui

TRANSLATIONS += \
    lang/wizualizacjaRobotaMobilnegoSterowanegoGestami_en_150.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    img/led/led_blue.png \
    img/led/led_green.png \
    img/led/led_lightGray.png \
    img/led/led_red.png \
    img/led/led_yellow-00.png \
    img/led/led_yellow-01.png \
    img/led/led_yellow-02.png \
    img/led/led_yellow-03.png \
    img/led/led_yellow-04.png \
    img/led/led_yellow-05.png \
    img/led/led_yellow-06.png \
    img/led/led_yellow-07.png \
    img/led/led_yellow-08.png \
    img/led/led_yellow-09.png \
    img/led/led_yellow-10.png \
    img/led/led_yellow-11.png \
    img/led/led_yellow.png \
    img/misc/exit.png \
    img/misc/settings.png \
    lang/wizualizacjaRobotaMobilnegoSterowanegoGestami_en_150.qm

RESOURCES += \
    res.qrc
