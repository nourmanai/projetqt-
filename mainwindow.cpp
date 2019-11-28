#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"personnel.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString nom= ui->nom->text();
       QString prenom= ui->prenom->text();
 int ID= ui->cin->text().toInt();
  int CIN= ui->id->text().toInt();
  pesonnel p(CIN,ID,nom,prenom);
  bool test=p.ajouter();
  if(test)
  { QMessageBox::critical(nullptr,QObject::tr("Ajout avec succes"),
                          QObject::tr("connection successful\n ""Click cancel to exite "),QMessageBox::Cancel);

  }
  else
  { QMessageBox::critical(nullptr,QObject::tr("Ajout!!!!"),
                          QObject::tr("noooo\n ""Click cancel to exite "),QMessageBox::Cancel);

  }


}

void MainWindow::on_pushButton_15_clicked()
{

    int cin = ui->lineEdit_8->text().toInt();
        QSqlQuery query;
        query.prepare("delete from PERSONNEL where CIN= :nombre");
        query.bindValue(":nombre",cin);
        bool v=query.exec();
        if(v)
        {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un personnel"),
                        QObject::tr("personnel supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("personnel n'existe pas !"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}}

void MainWindow::on_pushButton_2_clicked()
{
    QSqlQuery query;
    ui->listWidget->clear();
    query.exec("select * from PERSONNEL ORDER BY ID DESC");
    while(query.next())
    {

     QString id=query.value(0).toString();
     QString nom=query.value(1).toString();
     QString prenom=query.value(2).toString();
     QString cin=query.value(3).toString();
     QString ch=id+"                                              "+nom+"                                              "+prenom+"                                              "+cin;
     ui->listWidget->addItem(ch);

    }
}


void MainWindow::on_pushButton_16_clicked()
{
    QSqlQuery query;
            QString cin = ui->cin_9->text();

            QString prenom=ui->prenom_9->text();
            query.prepare("update PERSONNEL set PRENOM:=prenom WHERE CIN=:cin ");
            query.bindValue(":cin",cin);
           // query.bindValue(":nom",nom);
            query.bindValue(":prenom",prenom);

                   bool t=query.exec();
                   if(t)
                   {
                   QMessageBox::information(nullptr, QObject::tr("Modifier"),
                                   QObject::tr("état modifié.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                   }
                   else
                      { QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                                   QObject::tr("Erreur !.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}
}





void MainWindow::on_cin1_textChanged(const QString &cin1)
{
    ui->listWidget_5->clear();
        QSqlQuery query;
        //query.prepare("SELECT * from PERSONNEL where CIN=:nombre");
        query.prepare("SELECT * from PERSONNEL where substr(to_char(CIN),1,:size) like :nombre");
        query.bindValue(":nombre",cin1);
        query.bindValue(":size",cin1.size());
        query.exec();
        while(query.next())
        {
            QString id=query.value(0).toString();
            QString nom=query.value(1).toString();
            QString prenom=query.value(2).toString();
            QString cin=query.value(3).toString();
            QString ch=id+"                                              "+nom+"                                              "+prenom+"                                              "+cin;
            ui->listWidget_5->addItem(ch);

        }

}
