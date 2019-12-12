#include "transport.h"
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include"connection.h"
Transport::Transport()
{

    pointdepart="";
    pointarriv="";
    datedepart="";
    heuredepart="";
    id2=0;
    numtaxi=0;
    numchauffeure=0;


}
Transport::Transport(int id2,QString pointdepart,QString pointarriv,QString datedepart,QString heuredepart,int numtaxi,int numchauffeure)
{
    this->id2=id2;
     this->pointdepart=pointdepart;
     this->pointarriv=pointarriv;
     this->datedepart=datedepart;
     this->heuredepart=heuredepart;
     this->numtaxi=numtaxi;
     this->numchauffeure=numchauffeure;

}
QString Transport::get_pointdepart(){return pointdepart;}
QString Transport::get_pointarriv(){return pointarriv;}
QString Transport::get_datedepart(){return datedepart;}
QString Transport::get_heuredepart(){return heuredepart;}
int Transport::get_id2(){return id2;}
int Transport::get_numtaxi(){return numtaxi;}
int Transport::get_numchauffeure(){return numchauffeure;}



bool Transport::ajoutercTransport()
{
QSqlQuery query;
//QString res= QString::number(id2);
//QString res1=QString::number(numtaxi);
//QString res2=QString::number(numchauffeure);


query.prepare("INSERT INTO transport (ID2,POINTDEPART ,POINTARRIV ,DATEDEPART,HEUREDEPART,NUMTAXI,NUMCHAUFFEURE) "
                    "VALUES (:id2, :pointdepart, :pointarriv, :datedepart, :heuredepart, :numtaxi, :numchauffeure)");
query.bindValue(":id2", id2);
query.bindValue(":pointdepart",pointdepart);
query.bindValue(":pointarriv", pointarriv);
query.bindValue(":datedepart", datedepart);
query.bindValue(":heuredepart",heuredepart );
query.bindValue(":numtaxi", numtaxi);
query.bindValue(":numchauffeure", numchauffeure);
return    query.exec();

}


QSqlQueryModel * Transport::afficher_Transport()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Transport");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID2"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("POINTDEPART"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("POINTARRIV"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATEDEPART"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("HEUREDEPART"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMTAXI"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUMCHAUFFEURE"));
    return model;
}

QSqlQueryModel *Transport::getAllTransport()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Transport");
    return model;
}
bool Transport::supprimer_Transport(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Transport where ID2 = :id2 ");
query.bindValue(":id2",res);
return    query.exec();
}


bool Transport::modifier(Transport T)
{
    QSqlQuery query;

       query.prepare("UPDATE TABTRANSPORT SET ID2=id2,POINTDEPART=pointdepart,POINTARRIV=pointarriv,DATEDEPART=datedepart,HEUREDEPART=heuredepart,NUMTAXI=numtaxi,NUMCHAUFFEURE=numchauffeure ");
       query.bindValue(":id2", T.get_id2());
       query.bindValue(":pointdepart", T.get_pointdepart());
       query.bindValue(":pointarriv",T.get_pointarriv());
       query.bindValue(":datedepart", T.get_datedepart());
       query.bindValue(":heuredepart", T.get_heuredepart());
       query.bindValue(":numtaxi", T.get_numtaxi());
       query.bindValue(":numchauffeure", T.get_numchauffeure());

    return query.exec();
}

QSqlQueryModel * Transport::tri()
{
QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from transport     order by ID2 ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID2"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("POINTDEPART"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("POINTARRIV"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATEDEPART"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("HEUREDEPART"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMTAXI"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUMCHAUFFEURE"));
    return model;

}


QSqlQueryModel *Transport::rechercherid2(int id2)
{


QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query ;
QString res=QString::number(id2) ;

model->setQuery("select * from Transport where ID2='"+res+"'");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID2"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("POINTDEPART"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("POINTARRIV"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATEDEPART"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("HEUREDEPART"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMTAXI"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUMCHAUFFEURE"));
return model;
}
