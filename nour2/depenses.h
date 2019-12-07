#ifndef DEPENSES_H
#define DEPENSES_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QSqlQueryModel>

class Depenses
{
private:
     int id_depense;
    QString type_depense;
    float taux_TVA;
    float somme ;


public:
    Depenses();
    Depenses( int ,QString,float,float);

    bool ajouter_depense();
    QSqlQueryModel * afficher_depense();
    bool supprimer_depense(int);
      int get_id_depenses();
     QString get_type_depenses();
     QSqlQueryModel *tri_depense();
        QSqlQueryModel * recherche_depense(QSqlQuery query);

};

#endif // DEPENSES_H
