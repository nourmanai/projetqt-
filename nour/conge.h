#ifndef CONGE_H
#define CONGE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QSqlQueryModel>

class Conge
{
private :
     int id_conge ;
     QString date_debut;
     QString date_fin ;
     QString date_demande;
     QString etat_conge;
     int id_personnel;


public:
    Conge();
    Conge( int ,QString,QString,QString,QString,int);

    bool ajouter_conge();
    QSqlQueryModel * afficher_conge();
    bool supprimer_conge(int);
      int get_id_conge();

};

#endif // CONGE_H
