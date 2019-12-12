#include "reservation.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QDebug>
#include <QString>
#include <QDate>
#include"billet.h"

reservation::reservation()
{
    id=0;
    destination="";
    mode_paiement="";

}
reservation::reservation(int id,QString destination,QString mode_paiement,int id_offre,int id_client,int id_guide,int id_hotel,int num_billet ,QString date)
{
  this->id=id;
  this->destination=destination;
  this->mode_paiement=mode_paiement;
    this->date=date ;
    this->id_hotel=id_hotel;
    this->id_offre=id_offre;
    this->num_billet=num_billet;
    this->id_client=id_client;
    this->id_guide=id_guide;
}
QString reservation::get_destination(){return  destination;}
QString reservation::get_mode_paiement(){return mode_paiement;}
int reservation::get_id(){return  id;}

bool reservation::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
QString res1=QString::number(id_client);
QString res2=QString::number(id_guide);
QString res3=QString::number(id_hotel);
QString res4=QString::number(id_offre);
QString res5=QString::number(num_billet);


query.prepare("insert into RESERVATION (ID,MODE_PAIEMENT,DESTINATION,ID_HOTEL,NUM_BILLET,ID_OFFRE,ID_GUIDE,DATER,ID_CLIENT) values (:ID,:MODE_PAIEMENT,:DESTINATION,:ID_HOTEL,:NUM_BILLET,:ID_OFFRE,:ID_GUIDE,:DATER,:ID_CLIENT)");
query.bindValue(":ID", res);
query.bindValue(":MODE_PAIEMENT", mode_paiement);
query.bindValue(":DESTINATION", destination);
query.bindValue(":ID_HOTEL",res3);
query.bindValue(":NUM_BILLET",res5);
query.bindValue(":ID_OFFRE",res4);
query.bindValue(":ID_GUIDE",res2);
query.bindValue(":DATER",date);
query.bindValue(":ID_CLIENT",res1);

return    query.exec();
}

QSqlQueryModel * reservation::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from RESERVATION");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESTINATION"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MODE_PAIEMENT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_HOTEL"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUM_BILLET"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_OFFRE"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID_GUIDE"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("DATER"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("ID_CLIENT"));

    return model;
}
QSqlQueryModel* reservation::rechercher(int id)
{QSqlQueryModel * model= new QSqlQueryModel();

    QString res= QString::number(id);


    model->setQuery("select * from RESERVATION where ID='"+res+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESTINATION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MODE_PAIEMENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_HOTEL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUM_BILLET"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_OFFRE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID_GUIDE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("DATER"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("ID_CLIENT"));

 return model;



}
bool reservation::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from RESERVATION where ID=:ID ");
query.bindValue(":ID", res);
return    query.exec();
}

bool reservation::modifier(int id,QString destination,QString mode_paiement,int id_offre,int id_client,int id_guide,int id_hotel,int num_billet ,QString date)
{
QSqlQuery query ;
QString res= QString::number(id);
QString res1=QString::number(id_client);
QString res2=QString::number(id_guide);
QString res3=QString::number(id_hotel);
QString res4=QString::number(id_offre);
QString res5=QString::number(num_billet);
query.prepare("Update RESERVATION set MODE_PAIEMENT=:MODE_PAIEMENT,DESTINATION=:DESTINATION,ID_HOTEL=:ID_HOTEL,NUM_BILLET=:NUM_BILLET,ID_OFFRE=:ID_OFFRE,ID_GUIDE=:ID_GUIDE,DATER=:DATER,ID_CLIENT=:ID_CLIENT where ID=:ID");
query.bindValue(":ID", res);
query.bindValue(":MODE_PAIEMENT", mode_paiement);
query.bindValue(":DESTINATION", destination);
query.bindValue(":ID_HOTEL",res3);
query.bindValue(":NUM_BILLET",res5);
query.bindValue(":ID_OFFRE",res4);
query.bindValue(":ID_GUIDE",res2);
query.bindValue(":DATER",date);
query.bindValue(":ID_CLIENT",res1);

return    query.exec();
}
QSqlQueryModel * reservation::tri_affiche()
{ QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from RESERVATION ORDER BY ID");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESTINATION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MODE_PAIEMENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_HOTEL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUM_BILLET"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_OFFRE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID_GUIDE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("DATER"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("ID_CLIENT"));

        return model;


}
