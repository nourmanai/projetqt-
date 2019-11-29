#include "depenses.h"
#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <QSqlError>
#include "mainwindow.h"

Depenses::Depenses()
{
     id_depense =111;
    type_depense="";
     taux_TVA=0;
     somme=0 ;

}
Depenses::Depenses( int id_depense, QString type_depense,float taux_TVA,float somme)
{
 this->id_depense=id_depense ;
 this->type_depense=type_depense;
  this ->taux_TVA =taux_TVA;
   this ->somme =somme ;


}

int Depenses::get_id_depenses(){return  id_depense;}
QString Depenses::get_type_depenses(){return  type_depense;}

bool Depenses::ajouter_depense()
{
QSqlQuery query;
QString res= QString :: number (id_depense);
QString res1=QString :: number(taux_TVA);
QString res2=QString :: number(somme);
query.prepare("insert into DEPENSES (ID_DEPENSE,TYPE_DEPENSE,TAUX_TVA,SOMME) values (:ID_DEPENSE , :TYPE_DEPENSE ,:TAUX_TVA ,:SOMME)");

//qDebug()<<"jjjjjjjjjjjjjjj"<<res;
query.bindValue(":ID_DEPENSE", res);
query.bindValue(":TYPE_DEPENSE",type_depense);
query.bindValue(":TAUX_TVA",res1 );
query.bindValue(":SOMME",res2 );

return    query.exec();
}
QSqlQueryModel * Depenses::afficher_depense()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from DEPENSES");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_DEPENSE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_DEPENSE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TAUX_TVA"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("SOMME"));

    return model;
}
bool Depenses::supprimer_depense(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from depenses where ID_DEPENSE = :id_depense ");
query.bindValue(":id_depense",res);
return    query.exec();
}
