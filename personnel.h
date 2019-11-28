#ifndef PERSONNEL_H
#define PERSONNEL_H
#include<QString>
#include<QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlDatabase>

class pesonnel
{
public:
    pesonnel();
    pesonnel(int,int,QString,QString);
int  get_cin();
int  get_id();
   QString get_nom();
   QString get_prenom();
   bool ajouter();
   QSqlQueryModel *afficher();
   bool supprimer(int);

private:
    QString prenom;
   QString nom;
   int cin;
   int id;
};

#endif // PESONNEL_H
