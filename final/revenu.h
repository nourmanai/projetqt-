#ifndef REVENU_H
#define REVENU_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QSqlQueryModel>

class Revenu
{
private:
    int id_revenu;
    float revenu_net;
      QString type_revenu;
    float prix_facture;
    float prix_achat;
    float encaissement;
    float total_encaissement;
    int id_depense;
public:
    Revenu();
    Revenu(int ,float,QString,float,float,float,float,int);

    bool ajouter_revenu();
    QSqlQueryModel * afficher_revenu();
    bool supprimer_revenu(int);
    float calculer_revenu_net();
    float calculer_encaissement();
    float get_encaissement() {return encaissement;}
    float calculer_total_encaissement(float);
     int get_id_revenu();
     QString get_type_revenu();
     void update_encaissement();
        QSqlQueryModel *tri_revenu();
          QSqlQueryModel * recherche_revenu(QSqlQuery query);
};

#endif // REVENU_H
