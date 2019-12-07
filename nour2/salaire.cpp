#include "salaire.h"
#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <QSqlError>
#include "menuadmin.h"

Salaire::Salaire()
{

}
Salaire::Salaire(int id_salaire,QDate date_versement, QDate date_modification,float montant_salaire ,int sanction,int promotion ,QString nom_personnel)
{
     this->id_salaire=id_salaire;
     this->date_versement=date_versement;
     this->date_modification=date_modification;
      this->montant_salaire=montant_salaire;
    this->sanction=sanction;
    this->promotion=promotion;
    this-> nom_personnel=nom_personnel;
}
bool Salaire::ajouter_salaire()
{
QSqlQuery query;
QString res= QString :: number (id_salaire);
QString res3= QString :: number (montant_salaire);

query.prepare("insert into SALAIRE (ID_SALAIRE,DATE_VERSEMENT,DATE_MODIF,MONTANT_SALAIRE,NOM_PERSONNEL) values (:ID_SALAIRE, :DATE_VERSEMENT,:DATE_MODIF,:MONTANT_SALAIRE,:NOM_PERSONNEL)");

qDebug()<<"jjjjjjjjjjjjjjj"<<res;
query.bindValue(":ID_SALAIRE", res);
query.bindValue(":DATE_VERSEMENT",date_versement);
query.bindValue(":DATE_MODIF",date_modification);
query.bindValue(":MONTANT_SALAIRE",res3);
query.bindValue(":NOM_PERSONNEL",nom_personnel);


return    query.exec();
}
QSqlQueryModel * Salaire:: afficher_salaire()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from SALAIRE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_SALAIRE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_VERSEMENT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_MODIFICATION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MONTANT_SALAIRE"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("SANCTION"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("PROMOTION"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOM_PERSONNEL"));

        return model;
}
bool  Salaire::supprimer_salaire(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from salaire where ID_SALAIRE = :id_salaire");
    query.bindValue(":id_salaire",res);
    return    query.exec();
}
float  Salaire:: ajouter_sanction()
{
    QSqlQuery query;
    QString res= QString :: number (sanction);
   query.prepare("insert into SALAIRE (SANCTION) values (:SANCTION)");
    query.bindValue(":SANCTION", res);
    montant_salaire= montant_salaire-((montant_salaire*sanction)/100);
    return montant_salaire;

}
float  Salaire:: ajouter_promotion()
{
    QSqlQuery query;
    QString res= QString :: number (promotion);
   query.prepare("insert into SALAIRE (PROMOTION) values (:PROMOTION)");
    query.bindValue(":PROMOTION", res);
    montant_salaire= montant_salaire+((montant_salaire*sanction)/100);
    return montant_salaire;

}
QSqlQueryModel *Salaire::tri_affiche()
 {


     {
         QSqlQueryModel * model= new QSqlQueryModel();

         model->setQuery("select * from SALAIRE ORDER BY ID_SALAIRE");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_SALAIRE"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_VERSEMENT"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_MODIFICATION"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("MONTANT_SALAIRE"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("SANCTION"));
             model->setHeaderData(5, Qt::Horizontal, QObject::tr("PROMOTION"));

             return model;
     }

 }
QSqlQueryModel * Salaire::recherche_salaire(QSqlQuery query)
{
         QSqlQueryModel *model = new QSqlQueryModel();

            //query.prepare("select * from SALAIRE where NOM_PERSONNEL LIKE '"+nom+"' ");
           // query.prepare("select * from SALAIRE where NOM_PERSONNEL='"+w.get_ui()->lineEdit_cherch->text()+"'");

            //query.exec();
            model->setQuery(query);
            return model;
}
