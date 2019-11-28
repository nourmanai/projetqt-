#ifndef BILLET_H
#define BILLET_H
#include <QDate>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class billet
{
public:
    billet();
    billet(int,QString,QString,QString,QString,double,QString,QString);
    int get_numBillet() ;
    bool ajouter_billet() ;
    QSqlQueryModel * afficher();
    bool modifier(int);
    bool supprimer(int);
private:
        int num_billet;
    double prix ;
    QString date_aller,date_retour,date_vente,delai_annulation ;
    QString etat ,type ;


};

#endif // BILLET_H
