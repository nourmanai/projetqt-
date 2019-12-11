#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include"connection.h"
#include"transport.h"
#include <QMessageBox>
#include <QWidget>
#include <QObject>
#include <QSqlQueryModel>
#include <QtMultimedia/QMediaPlayer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/ASUS/Desktop/Faded - Alan Walker (Oud cover) by Ahmed Alshaiba.mp3")) ;
    player->setVolume(60);
    player->play();
    //QPixmap pix4("C:/Users/ASUS/Downloads/image.png");
    //ui->label_transport->setPixmap(pix4);
    //QPixmap pix5("C:/Users/ASUS/Downloads/image.png");
    //ui->label_transport_3->setPixmap(pix5);
    //QPixmap pix6("C:/Users/ASUS/Downloads/image.png");
   // ui->label_transport_4->setPixmap(pix6);
  // ui->tab_ajouter_client->setModel(c.ajouterclient());
  ui->table_afficher->setModel(c.afficher_client());
   ui->table_afficher->setModel(T.afficher_Transport());
  Connexion c;
  c.ouvrirConnexion();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()
{
    int id = ui->lineEdit->text().toInt();
     int tel = ui->lineEdit_6->text().toInt();
      int idreserv= ui->lineEdit_7->text().toInt();
    QString nom= ui->lineEdit_2->text();
    QString prenom= ui->lineEdit_3->text();
     QString adress= ui->lineEdit_4->text();
      QString email= ui->lineEdit_5->text();
  client c(id,nom , prenom , adress, email, tel, idreserv);

  bool test=c.ajouterclient();
  if(test)
{
    ui->table_afficher->setModel(c.afficher_client());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
}
void MainWindow::on_refresh_clicked()
{

    client *p=new client();
    ui->table_afficher->setModel(p->getAllclient());
}

void MainWindow::on_pushButton_clicked()
{
    int id = ui->lineEdit_7->text().toInt();
    bool test=c.supprimer_client(id);
    if(test)
    { ui->table_afficher->setModel(c.afficher_client());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Etudiant client.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_3_clicked()
{

    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare(" select * from client order by id");
    if (qry.exec())
    {
        while (qry.next())
                    {
         ui->id_input->setText(qry.value(0).toString());
         ui->tlf_input->setText(qry.value(1).toString());
         ui->idreserv_input->setText(qry.value(2).toString());
         ui->nom_input->setText(qry.value(5).toString());
         ui->prenom_input->setText(qry.value(3).toString());
         ui->adress_input->setText(qry.value(4).toString());

     }
     }
}

void MainWindow::on_pushButton_4_clicked()
{
    int id = ui->id_input->text().toInt();
     int tel = ui->tlf_input->text().toInt();
      int idreserv= ui->idreserv_input->text().toInt();
    QString nom= ui->nom_input->text();
    QString prenom= ui->prenom_input->text();
     QString adress= ui->adress_input->text();
      QString email= ui->mail_input->text();

      cl.modifier(id, nom , prenom , adress, email, tel, idreserv);
              client *R = new client(id, nom , prenom , adress, email, tel, idreserv) ;
     bool test = R->modifier(id, nom , prenom , adress, email, tel, idreserv) ;




 // client c(id,nom , prenom , adress, email, tel, idreserv);
 //bool test=modifier();

 if (test)
 { ui->table_afficher->setModel(c.afficher_client());
     QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                       QObject::tr(" client modifié .\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }
    }
/********************************************Selectionement************************************************/









void MainWindow::on_table_afficher_activated(const QModelIndex &index)
{
    QString val=ui->table_afficher->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare(" select * from client where Id='"+val+"' ");
    if (qry.exec())
    {
        while (qry.next())
                    {
         ui->id_input->setText(qry.value(0).toString());
         ui->tlf_input->setText(qry.value(1).toString());
         ui->idreserv_input->setText(qry.value(2).toString());
         ui->nom_input->setText(qry.value(5).toString());
         ui->prenom_input->setText(qry.value(3).toString());
         ui->adress_input->setText(qry.value(4).toString());

     }
     }
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->table_afficher->setModel(c.tri());
}
