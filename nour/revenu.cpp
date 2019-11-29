#include "revenu.h"
#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <QSqlError>
#include "mainwindow.h"

Revenu::Revenu()
{
     id_revenu=222;
     revenu_net=0;
       type_revenu="";
     prix_facture=0;
    prix_achat=0;
     encaissement=0;
    total_encaissement=0;
     id_depense=111;
}

Revenu::Revenu(int id_revenu ,float revenu_net,QString type_revenu,float prix_facture,float prix_achat,float encaissement,float total_encaissement,int id_depense)
{
    this->id_revenu =id_revenu;
   this->revenu_net= revenu_net;
      this->type_revenu= type_revenu;
    this->prix_facture= prix_facture;
   this->prix_achat= prix_achat;
    this->encaissement= encaissement;
    this->total_encaissement= total_encaissement;
    this->id_depense =id_depense;
}

int Revenu::get_id_revenu(){return  id_revenu;}
QString Revenu::get_type_revenu(){return  type_revenu;}


bool Revenu::ajouter_revenu()
{
    QSqlQuery query;
     calculer_encaissement();
    QString res= QString :: number (id_revenu);
    QString res3= QString :: number (prix_facture);
    QString res4= QString :: number (prix_achat);
    QString res5= QString :: number (encaissement);


    query.prepare("insert into REVENU (ID_REVENU,TYPE_REVENU,PRIX_FACTURE,PRIX_ACHAT,ENCAISSEMENT) values (:ID_REVENU,:TYPE_REVENU,:PRIX_FACTURE,:PRIX_ACHAT,:ENCAISSEMENT)");

  //  qDebug()<<"jjjjjjjjjjjjjjj"<<res;
  //   qDebug()<<"jjjjjjjjjjjjjjj"<<res3;
  //    qDebug()<<"jjjjjjjjjjjjjjj"<<res4;
    query.bindValue(":ID_REVENU", res);
    // query.bindValue(":REVENU_NET",revenu_net);
    query.bindValue(":TYPE_REVENU",type_revenu);
    query.bindValue(":PRIX_FACTURE",res3);
    query.bindValue(":PRIX_ACHAT",res4);

    query.bindValue(":ENCAISSEMENT",res5);
    // query.bindValue(":TOTAL_ENCAISS",total_encaissement);
    // query.bindValue(":ID_DEPENSE",id_depense);



return    query.exec();
}


QSqlQueryModel * Revenu ::afficher_revenu()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from revenu");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_REVENU"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("REVENU_NET"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_REVENU"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX_FACTURE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX_ACHAT"));
calculer_encaissement();
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ENCAISSEMENT"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("TOTAL_ENCAISSEMENT"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("ID_DEPENSE"));

    return model;
}

bool Revenu::supprimer_revenu(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from revenu where ID_REVENU = :id_revenu ");
query.bindValue(":id_revenu",res);
return    query.exec();
}
float Revenu::calculer_encaissement()
{
    QSqlQuery query;
    encaissement=prix_facture-prix_achat;
    query.prepare("insert into REVENU (ENCAISSEMENT) values (:ENCAISSEMENT)");
     QString res5= QString :: number (encaissement);
       query.bindValue(":ENCAISSEMENT",res5);

    return encaissement;
}
void Revenu::update_encaissement()
{
    QSqlQuery q;

    float x=calculer_encaissement();

  q.bindValue(":encaissement",x);

}
