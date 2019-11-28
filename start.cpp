
#include "start.h"
#include "ui_start.h"
#include "reservation.h"
#include <QMessageBox>
#include <QFrame>
#include <QPushButton>
#include <QString>
#include <QDate>
#include "billet.h"
#include<QPixmap>
#include <QtMultimedia/QMediaPlayer>


start::start(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::start)
{
ui->setupUi(this);
QMediaPlayer *player = new QMediaPlayer;
player->setMedia(QUrl::fromLocalFile("C:/Users/admin/Downloads/Rockabye - Clean Bandit (Oud cover) by Ahmed Alshaiba.mp3"));
player->setVolume(50);
player->play();
ui->frame_hotel->setDisabled(1);
ui->tabWidget_2->hide();
ui->frame_billet->setDisabled(1);
ui->frame_guide->setDisabled(1);
QPixmap pix("C:/Users/admin/Desktop/the hive/start.png");
ui->label_pic->setPixmap(pix);
QPixmap pix1("C:/Users/admin/Desktop/hot.png");
ui->label_hotel->setPixmap(pix1);
QPixmap pix2("C:/Users/admin/Desktop/plane.png");
ui->label_billet->setPixmap(pix2);
QPixmap pix3("C:/Users/admin/Desktop/guide.png");
ui->label_guide->setPixmap(pix3);
QPixmap pix4("C:/Users/admin/Desktop/transport.png");
ui->label_transport->setPixmap(pix4);



}

start::~start()
{
    delete ui;
}

void start::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString destination= ui->lineEdit_des->text();
  QString mode_paiement=ui->lineEdit_3->text();
    int id_offre=ui->lineEdit_offre->text().toInt();
    int id_client=ui->lineEdit_client->text().toInt();
    int id_guide=ui->lineEdit_guide->text().toInt();
    int id_hotel=ui->lineEdit_hotel->text().toInt();
    int num_billet=ui->lineEdit_num_billet->text().toInt();
    QString date= ui->dateEdit->text();
    QString date_vente= ui->dateTimeEdit_vente->text();
    QString date_aller= ui->dateTimeEdit_aller->text();
    QString date_retour= ui->dateTimeEdit_retour->text();
    QString delai_annulation= ui->dateEdit_delai->text();
    QString etat =ui->lineEdit_etat->text();
    QString type =ui->lineEdit_type->text();
    double prix = ui->lineEdit_prix->text().toDouble() ;


  reservation r( id, destination, mode_paiement, id_offre, id_client, id_guide, id_hotel, num_billet , date);
  billet b(num_billet,date_vente,date_aller,date_retour,delai_annulation,prix,etat,type) ;
  bool test=r.ajouter();
  bool test1=b.ajouter_billet();
  if( test1 && test)
{ui->tabreservation->setModel(tmpreservation.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un e reservation"),
                  QObject::tr("reservation ajouté.\n" "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une reservation"),
                  QObject::tr("Erreur !.\n" "Click Cancel to exit."), QMessageBox::Cancel);


}

void start::on_pb_supprimer_clicked()
{

int id = ui->lineEdit_id->text().toInt();
int num= ui->lineEdit_num_billet->text().toInt();
bool test=tmpreservation.supprimer(id);

bool test1=tmpbillet.supprimer(num);
if( test1)
{
    ui->tabreservation->setModel(tmpreservation.afficher());//refresh
    ui->tabbillet->setModel(tmpbillet.afficher()) ;
    QMessageBox::information(nullptr, QObject::tr("Supprimer un reservation"),QObject::tr("reservation supprimé.\n""Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un reservation"),QObject::tr("Erreur !.\n""Click Cancel to exit."), QMessageBox::Cancel);


}








void start::on_mise_a_jour_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString destination= ui->lineEdit_des->text();
    QString mode_paiement= ui->lineEdit_3->text();
    int id_offre=ui->lineEdit_offre->text().toInt();
    int id_client=ui->lineEdit_client->text().toInt();
    int id_guide=ui->lineEdit_guide->text().toInt();
    int id_hotel=ui->lineEdit_hotel->text().toInt();
    int num_billet=ui->lineEdit_num_billet->text().toInt();
    QString date= ui->dateEdit->text();
    QString date_vente= ui->dateTimeEdit_vente->text();
    QString date_aller= ui->dateTimeEdit_aller->text();
    QString date_retour= ui->dateTimeEdit_retour->text();
    QString delai_annulation= ui->dateEdit_delai->text();
    QString etat =ui->lineEdit_etat->text();
    QString type =ui->lineEdit_type->text();
    double prix = ui->lineEdit_prix->text().toDouble() ;
  reservation r( id, destination, mode_paiement, id_offre, id_client, id_guide, id_hotel, num_billet , date);
  billet b(num_billet,date_vente,date_aller,date_retour,delai_annulation,prix,etat,type) ;
  bool test=r.modifier(id,destination,mode_paiement,id_offre,id_client,id_guide,id_hotel,num_billet,date);
  bool test1=b.modifier(num_billet);
  if(test && test1)
{ui->tabreservation->setModel(tmpreservation.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une reservation"),
                  QObject::tr("reservation updated.\n" "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une reservation"),
                  QObject::tr("Erreur !.\n" "Click Cancel to exit."), QMessageBox::Cancel);


}





void start::on_afficher_clicked()
{  ui->tabbillet->setModel(tmpbillet.afficher());
  ui->tabWidget_2->show();
    ui->tabreservation_2->setModel(tmpreservation.afficher());
}

void start::on_tabreservation_2_activated(const QModelIndex &index)
{

}

void start::on_checkBox_guide_toggled(bool checked)
{
   ui->frame_guide->setEnabled(1);
}

void start::on_checkBox_billet_toggled(bool checked)
{
    ui->frame_billet->setEnabled(1) ;
}



void start::on_checkBox_3_toggled(bool checked)
{
    ui->frame_hotel->setEnabled(1);
}
