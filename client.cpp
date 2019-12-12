#include "client.h"
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include"connection.h"

client::client()
{
    id=0;
    tel=0;
    idreserv=0;
            nom="";
            prenom="";
            adress="";
            email="";

}

client::client(int id,QString nom ,QString prenom ,QString adress,QString email,int tel,int idreserv)
{
this->id=id;
 this->tel=tel;
 this->idreserv=idreserv;
 this->nom=nom;
 this->prenom=prenom;
 this->adress=adress;
 this->email=email;

}

QString client::get_nom(){return nom;}
QString client::get_prenom(){return prenom;}
QString client::get_adress(){return adress;}
QString client::get_email(){return email;}
int client::get_id(){return id;}
int client::get_tel(){return tel;}
int client::get_idreserv(){return idreserv;}



bool client::ajouterclient()
{
Connexion c;
c.ouvrirConnexion();

QSqlQuery query;
QString res= QString::number(id);


query.prepare("INSERT INTO client (ID, NOM, PRENOM,ADRESS,EMAIL,TEL,IDRESERV) "
                    "VALUES (:id, :nom, :prenom, :adress, :email, :tel, :idreserv)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adress", adress);
query.bindValue(":email",email );
query.bindValue(":tel", tel);
query.bindValue(":idreserv", idreserv);
return    query.exec();

}

QSqlQueryModel * client::afficher_client()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("IDRESERV"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESS"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("TLF"));
    return model;
}

QSqlQueryModel *client::getAllclient()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM client");
    return model;
}

bool client::supprimer_client(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from client where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool client::modifier(int id,QString nom ,QString prenom ,QString adress,QString email,int tel,int idreserv)
{
    QSqlQuery query;


       query.prepare("UPDATE CLIENT SET ID=:id,NOM=:nom,PRENOM=:prenom,ADRESS=:adress,EMAIL=:email,TEL=:tel,IDRESERV=:idreserv WHERE id=:id ");
       query.bindValue(":id", id);
       query.bindValue(":nom",nom);
       query.bindValue(":prenom",prenom);
       query.bindValue(":adress",adress);
       query.bindValue(":email",email);
       query.bindValue(":tel",tel);
       query.bindValue(":idreserv",idreserv);



    return query.exec();
}
QSqlQueryModel * client::tri()
{
QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from client order by ID asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Tel"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Idreserv"));
return model;
}


QSqlQueryModel *client::recherchernomclient(int id)

{

QSqlQueryModel * model= new QSqlQueryModel();
  QString res= QString::number(id);

model->setQuery("select * from CLIENT where ID  ='"+res+"' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("IDRESERV"));

return model;
}

