#ifndef PARTENAIRE_H
#define PARTENAIRE_H

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


namespace Ui {
class Partenaire;
}

class Partenaire : public QDialog
{
    Q_OBJECT

public:

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

    explicit Partenaire(QWidget *parent = 0);
    ~Partenaire();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    //void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_recherche_textChanged(const QString &arg1);

    void on_recherche_2_textChanged(const QString &arg1);

    void on_pushButton_13_clicked();

    void on_Stat_clicked();

private:
    int id;
    QString nom;
    QString adresse;
    QString mail;
    QString type;
    int id_contrat;

    Ui::Partenaire *ui;
};

#endif // PARTENAIRE_H
