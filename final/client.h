#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class client
{
public:
    client();
    client(int,QString,QString,QString,QString,int,int);
       QString get_nom();
       QString get_prenom();
       QString get_adress();
       QString get_email();
       int get_id();
       int get_tel();
       int get_idreserv();
       bool ajouterclient();
      QSqlQueryModel * afficher_client();
      QSqlQueryModel* getAllclient();
      bool supprimer_client(int idd);
       bool modifier(int,QString,QString,QString,QString,int,int);
       QSqlQueryModel *tri();
        QSqlQueryModel *recherchernomclient(QString );
private:
    QString nom,prenom,adress,email;
    int id,tel,idreserv;

};

#endif // CLIENT_H
