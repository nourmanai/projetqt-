#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<QString>
#include<QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlDatabase>

class personnel
{
public:
    personnel();
    personnel(int,int,QString,QString);
    int  get_cin();
    int  get_id();
       QString get_nom();
       QString get_prenom();
       bool ajouter();
       QSqlQueryModel *afficher();
       bool supprimer(int);

    private:
        QString prenom;
       QString nom;
       int cin;
       int id;
};

#endif // PERSONNEL_H
