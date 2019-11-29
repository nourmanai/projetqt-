#-------------------------------------------------
#
# Project created by QtCreator 2019-11-07T21:42:27
#
#-------------------------------------------------

QT       += core gui sql
CONFIG   += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetA2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    connexion.cpp \
    partenaire.cpp

HEADERS  += mainwindow.h \
    connexion.h \
    partenaire.h \
    contrat.h

FORMS    += mainwindow.ui \
    partenaire.ui
