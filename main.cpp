#include "mainwindow.h"
#include "partenaire.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Partenaire w;
    connexion cnx;
    bool create_test = cnx.createConnexion();
    if(create_test){
        w.show();
        QMessageBox::warning(nullptr, QObject::tr("Database is open"),QObject::tr("Connexion Successful.\n" "Click Cancel to exit."),
                QMessageBox::Cancel);
    }
    else{
        w.show();
        QMessageBox::critical(nullptr, QObject::tr("Database is open"),QObject::tr("Connexion Failed.\n" "Click Cancel to exit."),
                QMessageBox::Cancel);
    }
    return a.exec();
}
