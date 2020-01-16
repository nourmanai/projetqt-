QT       += core gui sql

QT       +=sql

QT       += core gui  serialport
QT += printsupport
 QT +=multimedia
QT       += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    arduino.cpp \
    billet.cpp \
    client.cpp \
    conge.cpp \
    connection.cpp \
    contrat.cpp \
    depenses.cpp \
    main.cpp \
    mainwindow.cpp \
    menu_admin.cpp \
    menu_agent.cpp \
    menu_com.cpp \
    notif.cpp \
    partenaire.cpp \
    personnel.cpp \
    reservation.cpp \
    revenu.cpp \
    salaire.cpp \
    stats.cpp \
    transport.cpp

HEADERS += \
    arduino.h \
    billet.h \
    client.h \
    conge.h \
    connection.h \
    contrat.h \
    depenses.h \
    mainwindow.h \
    menu_admin.h \
    menu_agent.h \
    menu_com.h \
    notif.h \
    partenaire.h \
    personnel.h \
    reservation.h \
    revenu.h \
    salaire.h \
    stats.h \
    transport.h

FORMS += \
    mainwindow.ui \
    menu_admin.ui \
    menu_agent.ui \
    menu_com.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
