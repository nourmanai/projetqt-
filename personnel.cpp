#include "personnel.h"
#include"conge.h"

pesonnel::pesonnel()
{
id=0;
cin=0;
nom="";
prenom="";
}

pesonnel::pesonnel(int id,int cin,QString nom,QString prenom)
{
    this->id=id;
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
}
int pesonnel::get_id(){return id ;}
int pesonnel::get_cin(){return cin ;}
QString pesonnel::get_nom(){return nom;}
QString pesonnel::get_prenom(){return prenom;}
bool pesonnel::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);
    QString res1=QString::number(cin);
    query.prepare("INSERT INTO PERSONNEL (CIN,ID,NOM,PRENOM)"
                      "VALUES (:cin, :id, :nom, :prenom)");
    query.bindValue(":cin", res1) ;
    query.bindValue(":id", res) ;
     query.bindValue(":nom", nom) ;
     query.bindValue(":prenom", prenom) ;
     return query.exec();
}

QSqlQueryModel * pesonnel::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PERSONNEL");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
    return model;
}
