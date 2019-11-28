#include "connexion.h"
#include<QMessageBox>


Connexion::Connexion()
{}

  bool Connexion::ouvrireconnexion()
  {  bool test = false;
      QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("source_project_2A8");
    db.setUserName("mohamed");
    db.setPassword("25163816");
    if(db.open())
      {
          test=true;
          return test;
      }
return test;
  }
  void Connexion::fermerconnexion()
  {db.close();}
