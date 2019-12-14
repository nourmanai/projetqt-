#include "personnel.h"
#include"conge.h"

personnel::personnel()
{
    id=0;
    cin=0;
    nom="";
    prenom="";
}




personnel::personnel(int id,int cin,QString nom,QString prenom)
{
    this->id=id;
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
}
int personnel::get_id(){return id ;}
int personnel::get_cin(){return cin ;}
QString personnel::get_nom(){return nom;}
QString personnel::get_prenom(){return prenom;}
bool personnel::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);
    QString res1=QString::number(cin);
    query.prepare("INSERT INTO PERSONNEL (NOM,ID,PRENOM,CIN)"
                      "VALUES (:nom, :id, :prenom, :cin)");
    query.bindValue(":cin", res1) ;
    query.bindValue(":id", res) ;
     query.bindValue(":nom", nom) ;
     query.bindValue(":prenom", prenom) ;
     return query.exec();
}

QSqlQueryModel * personnel::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PERSONNEL");
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
    return model;

}

