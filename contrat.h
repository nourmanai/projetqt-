#ifndef CONTRAT_H
#define CONTRAT_H
#include <QDialog>
#include <iostream>
#include <ostream>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <iostream>
#include <ostream>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <string.h>
#include <QCoreApplication>
#include <QtSql>
#include <QString>
#include <ctime>
#define q2c(string) string.toStdString()

class Contrat
{
public:

   // Contrat();
    int getId_contrat(){return Id_contrat;}
    void SetId_contrat(int Id_contrat){this->Id_contrat = Id_contrat;}

    QString getDate_debut_contrat(){return Date_debut_contrat;}
    void SetDate_debut_contrat(QString Date_debut_contrat){this->Date_debut_contrat = Date_debut_contrat;}

    QString getDate_fin_contrat(){return Date_fin_contrat;}
    void SetDate_fin_contrat(QString Date_fin_contrat){this->Date_fin_contrat = Date_fin_contrat;}





private:
    int Id_contrat;
    QString Date_debut_contrat;
    QString Date_fin_contrat;


};

#endif // CONTRAT_H
