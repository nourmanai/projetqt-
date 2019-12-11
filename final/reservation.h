#ifndef RESERVATION_H
#define RESERVATION_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>


class reservation
{
public:
    reservation();
    reservation(int,QString,QString,int,int,int,int,int,QString);
    QString get_destination();
      QString get_mode_paiement();
      int get_id();
      bool ajouter();
      QSqlQueryModel * afficher();
      bool supprimer(int);
      bool modifier(int,QString,QString,int,int,int,int,int,QString);
      QSqlQueryModel* rechercher(int);
      QSqlQueryModel* tri_affiche();

  private:
      QString destination,mode_paiement,date;
      int id,num_billet,id_offre,id_hotel,id_client,id_guide;
};

#endif // RESERVATION_H
