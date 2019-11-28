#ifndef CONNEXION_H
#define CONNEXION_H
#include <QtSql/QSqlDatabase>

class Connexion
{
private:
    QSqlDatabase db;
public:
    Connexion();
bool ouvrireconnexion();
void fermerconnexion();
};

#endif // CONNEXION_H
