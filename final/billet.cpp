#include "billet.h"

billet::billet()
{

}
billet::billet(int num_billet,QString date_vente,QString date_aller,QString date_retour,QString delai_annulation,double prix,QString type ,QString etat)
{
    this->num_billet=num_billet ;
    this->date_vente=date_vente ;
    this->date_aller=date_aller ;
    this->date_retour=date_retour;
    this->delai_annulation=delai_annulation;
    this->prix=prix ;
    this->type=type;
    this->etat=etat;
}
int billet::get_numBillet() {return num_billet ;}
bool billet::ajouter_billet()
{
    QSqlQuery query;
    QString res= QString::number(num_billet);
    QString res1=QString::number(prix);




    query.prepare("insert into BILLET (NUM_BILLET,DATE_VENTE,DATE_ALLER,DATE_RETOUR,DELAI_ANNULATION,PRIX,ETAT,TYPE) values (:NUM_BILLET,:DATE_VENTE,:DATE_ALLER,:DATE_RETOUR,:DELAI_ANNULATION,:PRIX,:ETAT,:TYPE)");
    query.bindValue(":NUM_BILLET", res);
    query.bindValue(":DATE_VENTE", date_vente);
    query.bindValue(":DATE_ALLER", date_aller);
    query.bindValue(":DATE_RETOUR",date_retour);
    query.bindValue(":DELAI_ANNULATION",res);
    query.bindValue(":PRIX",prix);
    query.bindValue(":ETAT",etat);
    query.bindValue(":TYPE",type);


    return    query.exec();
}
QSqlQueryModel * billet::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from BILLET");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_BILLET"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_VENTE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_ALLER"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_RETOUR"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DELAI_ANNULATION"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("TYPE"));

        return model;
}
bool billet::modifier(int)
{
    QSqlQuery query;
    QString res= QString::number(num_billet);
    QString res1=QString::number(prix);
    query.prepare("Update BILLET set DATE_VENTE=:DATE_VENTE,DATE_ALLER=:DATE_ALLER,DATE_RETOUR=:DATE_RETOUR,DELAI_ANNULATION=:DELAI_ANNULATION,PRIX=:PRIX,ETAT=:ETAT,TYPE=:TYPE where NUM_BILLET=:NUM_BILLET");
    query.bindValue(":NUM_BILLET", res);
    query.bindValue(":DATE_VENTE", date_vente);
    query.bindValue(":DATE_ALLER", date_aller);
    query.bindValue(":DATE_RETOUR",date_retour);
    query.bindValue(":DELAI_ANNULATION",res);
    query.bindValue(":PRIX",prix);
    query.bindValue(":ETAT",etat);
    query.bindValue(":TYPE",type);


    return    query.exec();
}
bool billet::supprimer(int num_billet)
{
    QSqlQuery query;
    QString res= QString::number(num_billet);
    query.prepare("Delete from BILLET where NUM_BILLET =:NUM_BILLET ");
    query.bindValue(":NUM_BILLET", res);
    return    query.exec();
}
