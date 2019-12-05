#include "partenaire.h"
#include "contrat.h"
#include "ui_partenaire.h"
#include <ctime>

Partenaire::Partenaire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Partenaire)
{
    ui->setupUi(this);
}

Partenaire::~Partenaire()
{
    delete ui;
}

void Partenaire::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Partenaire::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Partenaire::on_pushButton_4_clicked()
{

    //ajouter
    Partenaire p;

    qDebug()<<"Le Bouton Envoyer a ete appuie..."<<endl;

    p.SetId(ui->lineEdit_13->text().toULong());
    p.SetNom(ui->lineEdit_3->text());
    p.SetAdresse(ui->lineEdit_4->text());
    p.SetMail(ui->lineEdit_5->text());
    p.SetType(ui->lineEdit_14->text());
    p.SetId_contrat(ui->lineEdit_6->text().toULong());

    QSqlQuery query;

    query.prepare("INSERT INTO PARTENAIRE (ID, NOM, ADRESSE, MAIL, TYPE, ID_CONTRAT)"
                            "VALUES (: ID, : NOM, : ADRESSE, : MAIL, :TYPE, : ID_CONTRAT)");

    query.addBindValue(p.getId());
    query.addBindValue(p.getNom());
    query.addBindValue(p.getAdresse());
    query.addBindValue(p.getMail());
    query.addBindValue(p.getType());
    query.addBindValue(p.getId_contrat());
    query.exec();

    //afficher
    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery query2;
    query2.prepare("SELECT * FROM PARTENAIRE ")  ;
    query2.exec() ;
    model->setQuery(query2);
    ui->tableView-> setModel(model);
    qDebug()<<"Envoi effectue"<<endl;
}

void Partenaire::on_pushButton_3_clicked()
{
    //afficher
    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery query;
    query.prepare("SELECT * FROM PARTENAIRE ")  ;
    query.exec() ;
    model->setQuery(query);
    ui->tableView-> setModel(model);
}

void Partenaire::on_pushButton_6_clicked()
{
    //supprimer
    Partenaire p;
    QSqlQuery query;
    int id;
    p.SetId(ui->lineEdit_7->text().toULong());
    id = p.getId();

    query.prepare("delete from PARTENAIRE WHERE ID=?");
    query.addBindValue(id);
    if(query.exec())
    {
        std::cout << "La reclammation a bien été supprimer! :)" << std::endl;
        //afficher
        QSqlQueryModel * model=new QSqlQueryModel() ;
        QSqlQuery query;
        query.prepare("SELECT * FROM PARTENAIRE ")  ;
        query.exec() ;
        model->setQuery(query);
        ui->tableView-> setModel(model);
    }
    else
    {
        std::cout << "Suppri:( Une erreur s'est produite. :(" << std::endl << q2c(query.lastError().text()) << std::endl;
    }
}

void Partenaire::on_pushButton_5_clicked()
{
    //modifier
    Partenaire p;
    QSqlQuery query;
    p.SetNom(ui->lineEdit_3->text());
    p.SetId(ui->lineEdit_7->text().toULong());
    p.SetAdresse(ui->lineEdit_4->text());
    p.SetMail(ui->lineEdit_5->text());
    p.SetType(ui->lineEdit_14->text());
    p.SetId_contrat(ui->lineEdit_6->text().toULong());
    //id = p.get_id();

    query.prepare("UPDATE PARTENAIRE SET NOM =:NOM, ADRESSE=:ADRESSE, MAIL =:MAIL, TYPE =:TYPE, ID_CONTRAT =:ID_CONTRAT  WHERE ID=:ID") ;

    query.addBindValue(p.getNom());
    query.addBindValue(p.getAdresse());
    query.addBindValue(p.getMail());
    query.addBindValue(p.getType());
    query.addBindValue(p.getId_contrat());
    query.addBindValue(p.getId());

    if(query.exec())
    {
        std::cout << "Le partenaire a bien été modifier! :)" <<std::endl;
        //afficher
        QSqlQueryModel * model=new QSqlQueryModel() ;
        QSqlQuery query2;
        query2.prepare("SELECT * FROM PARTENAIRE ")  ;
        query2.exec() ;
        model->setQuery(query2);
        ui->tableView-> setModel(model);
    }
    else
    {
        std::cout << "Modif:( Desolé une erreur s'est produite. :(" << std::endl << q2c(query.lastError().text()) << std::endl;
    }
}

void Partenaire::on_pushButton_9_clicked()
{
    //ajouter
      Contrat c ;
      qDebug()<<"Le Bouton Envoyer a ete appuie..."<<endl;

      c.SetId_contrat(ui->lineEdit_8->text().toULong());
      c.SetDate_debut_contrat(ui->dateEdit->text());
      c.SetDate_fin_contrat(ui->dateEdit_2->text());



      QSqlQuery query;

      query.prepare("INSERT INTO CONTRAT (ID_CONTRAT, DATE_DEBUT_CONTRAT, DATE_FIN_CONTRAT)"
                              "VALUES (:ID_CONTRAT, :DATE_DEBUT_CONTRAT, :DATE_FIN_CONTRAT)");

      query.addBindValue(c.getId_contrat());
      query.addBindValue(c.getDate_debut_contrat());
      query.addBindValue(c.getDate_fin_contrat());

      query.exec();

      //afficher
      QSqlQueryModel * model=new QSqlQueryModel() ;
      QSqlQuery query2;
      query2.prepare("SELECT * FROM CONTRAT ")  ;
      query2.exec() ;
      model->setQuery(query2);
      ui->tableView_2-> setModel(model);
      qDebug()<<"Envoi effectue"<<endl;
}

void Partenaire::on_pushButton_8_clicked()
{
    //afficher
    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery query;
    query.prepare("SELECT * FROM CONTRAT ")  ;
    query.exec() ;
    model->setQuery(query);
    ui->tableView_2-> setModel(model);
}

void Partenaire::on_pushButton_11_clicked()
{
    //supprimer
    Contrat c;
    QSqlQuery query;
    int id;
    c.SetId_contrat(ui->lineEdit_12->text().toULong());
    id = c.getId_contrat();

    query.prepare("delete from CONTRAT WHERE ID_CONTRAT=:ID_CONTRAT ");
    query.addBindValue(id);
    if(query.exec())
    {
        std::cout << "Le contrat a bien été supprimer! :)" << std::endl;
        //afficher
        QSqlQueryModel * model=new QSqlQueryModel() ;
        QSqlQuery query;
        query.prepare("SELECT * FROM CONTRAT ")  ;
        query.exec() ;
        model->setQuery(query);
        ui->tableView_2-> setModel(model);
    }
    else
    {
        std::cout << "Suppri:( Une erreur s'est produite. :(" << std::endl << q2c(query.lastError().text()) << std::endl;
    }
}



void Partenaire::on_pushButton_10_clicked()
{
    //modifier
      Contrat c ;
      qDebug()<<"Le Bouton Envoyer a ete appuie..."<<endl;

      c.SetId_contrat(ui->lineEdit_12->text().toULong());
      c.SetDate_debut_contrat(ui->dateEdit->text());
      c.SetDate_fin_contrat(ui->dateEdit_2->text());



      QSqlQuery query;

      query.prepare("UPDATE CONTRAT SET DATE_DEBUT_CONTRAT=:DATE_DEBUT_CONTRAT, DATE_FIN_CONTRAT =:DATE_FIN_CONTRAT  WHERE ID_CONTRAT=:ID_CONTRAT") ;



      query.addBindValue(c.getDate_debut_contrat());
      query.addBindValue(c.getDate_fin_contrat());
      query.addBindValue(c.getId_contrat());

      query.exec();

      //afficher
      QSqlQueryModel * model=new QSqlQueryModel() ;
      QSqlQuery query2;
      query2.prepare("SELECT * FROM CONTRAT ")  ;
      query2.exec() ;
      model->setQuery(query2);
      ui->tableView_2-> setModel(model);
      qDebug()<<"Envoi effectue"<<endl;
}

void Partenaire::on_recherche_textChanged(const QString &arg1)
{

}

void Partenaire::on_recherche_2_textChanged(const QString &arg1)
{
    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery query2;
    query2.prepare("SELECT * FROM partenaire where nom like :test ")  ;
    query2.bindValue(":test",arg1+"%");
    query2.exec() ;
    model->setQuery(query2);
    ui->tableView-> setModel(model);
}

void Partenaire::on_pushButton_13_clicked()
{
    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery query2;
    query2.prepare("SELECT * FROM partenaire order by nom")  ;
    query2.exec() ;
    model->setQuery(query2);
    ui->tableView-> setModel(model);
}

void Partenaire::on_Stat_clicked()
{
    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery query2;
    query2.prepare("SELECT TYPE, COUNT(*) FROM partenaire group by type")  ;
    query2.exec() ;
    model->setQuery(query2);
    ui->tableView-> setModel(model);
}

void Partenaire::on_pushButton_clicked()
{

}
