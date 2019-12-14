#ifndef CONGE_H
#define CONGE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QSqlQueryModel>
#include <QDate>

#include <QTableView>

class conge
{
public:
    conge();
    conge(int,QString,QString ,int);
    int  get_id_conge();
    QString  get_debut_conge();
     QString  get_fin_conge();
     int get_id_personnel();
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel *afficher();
     bool modifier(int val ,QString debut_conge,QString fin_conge,int id_personnel);
private:
    QString debut_conge;
       QString fin_conge;
    int id_conge;
    int id_personnel;

};

#endif // CONGE_H
