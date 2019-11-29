#ifndef SALAIRE_H
#define SALAIRE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QDate>
#include <QSqlQueryModel>
#include <QTableView>

class salaire
{
private:
    int id_salaire;
    QDateTime date_versement;
    QDateTime date_modification;
     float montant_salaire ;
     int sanction;
     int promotion;
     QString nom_personnel;

public:
    salaire();
    salaire(int ,QDateTime ,QDateTime ,float,int,int,QString);
   bool ajouter_salaire();
   QSqlQueryModel * afficher_salaire();
   bool supprimer_salaire(int);
     int get_id_salaire();
    int get_montant();
    QDateTime get_date_versement(){return date_versement;}
     QDateTime get_date_modif(){return date_modification;}
    float ajouter_sanction();
    float ajouter_promotion();

  QSqlQueryModel * tri_affiche();
   QSqlQueryModel * recherche_salaire(QSqlQuery query);


};

#endif // SALAIRE_H
