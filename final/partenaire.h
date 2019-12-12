#ifndef PARTENAIRE_H
#define PARTENAIRE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
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
#include <QSerialPort>
#define q2c(string) string.toStdString()

class Partenaire: public QDialog
{
    Q_OBJECT
public:

    Partenaire();
    int getId(){return id;}
       void SetId(int id){this->id = id;}

       QString getNom(){return nom;}
       void SetNom(QString nom){this->nom = nom;}

       QString getAdresse(){return adresse;}
       void SetAdresse(QString adresse){this->adresse = adresse;}

       QString getMail(){return mail;}
       void SetMail(QString mail){this->mail = mail;}

       QString getType(){return type;}
       void SetType(QString type){this->type = type;}

       int getId_contrat(){return id_contrat;}
       void SetId_contrat(int id_contrat){this->id_contrat = id_contrat;}



private:
    int id;
    QString nom;
    QString adresse;
    QString mail;
    QString type;
    int id_contrat;
    QSerialPort arduino;
};

#endif // PARTENAIRE_H
