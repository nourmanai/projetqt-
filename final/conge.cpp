#include "conge.h"
#include <QSqlQueryModel>
#include<QSqlQuery>

conge::conge()
{
  debut_conge="";
  fin_conge="";
  id_conge=0;
}

conge::conge(int id_conge,QString debut_conge,QString fin_conge,int id_personnel)
{
    this->id_conge=id_conge;
    this->debut_conge=debut_conge;
    this->fin_conge=fin_conge;
    this->id_personnel=id_personnel;
}
int conge::get_id_conge(){return id_conge ;}
QString conge::get_debut_conge(){return debut_conge ;}
QString conge::get_fin_conge(){return fin_conge;}
int conge::get_id_personnel(){return id_personnel;}

bool conge::ajouter()
{
    QSqlQuery query;

    QString res=QString::number(id_conge);
    QString res3=QString::number((id_personnel));
    query.prepare("INSERT INTO CONGE (ID_CONGE,DEBUT_CONGE,FIN_CONGE,ID_PERSONNEL)" "VALUES (:ID_CONGE,:DEBUT_CONGE,:FIN_CONGE, :ID_PERSONNEL)");
    query.bindValue(":ID_CONGE",res) ;
    query.bindValue(":DEBUT_CONGE",debut_conge) ;
    query.bindValue(":FIN_CONGE",fin_conge) ;
    query.bindValue(":ID_PERSONNEL", res3) ;
     return query.exec();
}
QSqlQueryModel *conge::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CONGE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONGE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DEBUT_CONGE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("FIN_CONGE"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID_PERSONNEL"));

    return model;
}
bool conge::modifier(int id_conge,QString debut_conge,QString fin_conge,int id_personnel)
{
    QSqlQuery query;


       query.prepare("UPDATE CONGE SET DEBUT_CONGE=:debut_conge,FIN_CONGE=:fin_conge,ID_PERSONNEL=:id_personnel WHERE ID_CONGE=:id_conge ");

        query.bindValue(":ID_CONGE",id_conge) ;
       query.bindValue(":DEBUT_CONGE",debut_conge) ;
       query.bindValue(":FIN_CONGE",fin_conge) ;
       query.bindValue(":ID_PERSONNEL", id_personnel) ;


    return query.exec();
}
