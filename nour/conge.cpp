#include "conge.h"
#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <QSqlError>
#include "mainwindow.h"

Conge::Conge()
{

}
Conge::Conge( int id_conge,QString  date_debut,QString  date_fin,QString date_demande,QString  etat_conge,int id_personnel)
{
  this ->id_conge=id_conge ;
    this -> date_debut =date_debut;
    this -> date_fin  =date_fin;
  this -> date_demande =date_demande;
     this -> etat_conge =etat_conge;
   this -> id_personnel =id_personnel;
}

int Conge::get_id_conge(){return  id_conge;}

bool Conge::ajouter_conge()
{
    QSqlQuery query;
    QString res= QString :: number (id_conge);
    QString res1=date_debut;
    QString res2=date_fin;
     QString res3=date_demande;
      QString res4=etat_conge;
       QString res5=QString :: number (id_personnel);


    query.prepare("insert into CONGE (ID_CONGE,DATE_DEBUT,DATE_FIN,DATE_DEMANDE,ETAT_CONGE,ID_PERSONNEL) values (:ID_CONGE,:DATE_DEBUT,:DATE_FIN,:DATE_DEMANDE,:ETAT_CONGE,:ID_PERSONNEL)");

    //qDebug()<<"jjjjjjjjjjjjjjj"<<res;
    query.bindValue(":ID_DEPENSE", res);
    query.bindValue(":DATE_DEBUT",date_debut);
    query.bindValue(":DATE_FIN",date_fin);
    query.bindValue(":DATE_DEMANDE",date_demande );
    query.bindValue(":DATE_ETAT_CONGE",etat_conge );
    query.bindValue(":ID_PERSONNEL",id_personnel);

    return    query.exec();
    }

