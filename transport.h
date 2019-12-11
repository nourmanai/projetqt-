#ifndef TRANSPORT_H
#define TRANSPORT_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Transport
{
public:
    Transport();

    Transport(int,QString,QString,QString,QString,int,int);
    QString get_pointdepart();
    QString get_pointarriv();
    QString get_datedepart();
    QString get_heuredepart();
    int get_id2();
    int get_numtaxi();
    int get_numchauffeure();
    bool ajoutercTransport();
   QSqlQueryModel * afficher_Transport();
   bool supprimer_Transport(int idd);
   bool modifier (Transport T);
   QSqlQueryModel *tri();
    QSqlQueryModel *rechercherid2(int);




private:
    QString pointdepart,pointarriv,datedepart,heuredepart;
    int id2,numtaxi,numchauffeure;

};
#endif // TRANSPORT_H
