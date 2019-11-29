#include "connexion.h"

connexion::connexion()
{

}
bool connexion::createConnexion()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("Reine");
    db.setPassword("Mreine2001");
    if(db.open()){ return true; }
    return false;
}
