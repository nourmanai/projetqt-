#include "mainwindow.h"
#include<QDebug>
#include <QApplication>
#include<QMessageBox>
#include"connexion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
Connexion c;

bool test=c.ouvrireconnexion();
if(test)
{w.show();
    QMessageBox::critical(nullptr,QObject::tr("database is open"),
                          QObject::tr("connection successful\n ""Click cancel to exite "),QMessageBox::Cancel);
}
else {

    QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                          QObject::tr("connection Failed\n ""Click cancel to exite "),QMessageBox::Cancel);
}

    return a.exec();
}
