#ifndef CONGE_H
#define CONGE_H
#include<QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlDatabase>

class conge
{
public:
    conge();
    int  get_id_conge();
    int  get_debut_conge();
     int  get_fin_conge();
    int debut_conge;
    int fin_conge;
    int id_conge;

    bool ajouter_conge();
    bool modifier_conge();
private:

};

#endif // CONGE_H
