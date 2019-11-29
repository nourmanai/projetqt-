#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlQuery>
#include <QSqlDatabase>
#include<QDebug>
#include <QSqlError>

class connexion
{
public:
    connexion();
    bool createConnexion();
};

#endif // CONNEXION_H
