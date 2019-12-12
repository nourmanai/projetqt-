#include "menu_agent.h"
#include "ui_menu_agent.h"
#include "reservation.h"
#include "arduino.h"
#include <QMessageBox>
#include <QFrame>
#include <QPushButton>
#include <QString>
#include <QDate>
#include "billet.h"
#include "client.h"
#include<QPixmap>
#include <QDesktopServices>
#include <QPrinter>
#include <QPrintDialog>
#include <QtMultimedia/QMediaPlayer>
#include <QTextDocument>
#include <QScreen>
#include<QTimer>
#include <QSqlQueryModel>



menu_agent::menu_agent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu_agent)
{
    ui->setupUi(this);
    ui->table_afficher->setModel(c.afficher_client());
      ui->table_afficher->setModel(T.afficher_Transport());
    //QMediaPlayer *player = new QMediaPlayer;
   /* player->setMedia(QUrl::fromLocalFile("C:/Users/admin/Downloads/Rockabye - Clean Bandit (Oud cover) by Ahmed Alshaiba.mp3"));
    player->setVolume(50);
    player->play();*/
    ui->frame_hotel->setDisabled(1);
    ui->tabWidget_4->hide();
    ui->frame_billet->setDisabled(1);
    ui->frame_guide->setDisabled(1);
    /*QPixmap pix("C:/Users/admin/Desktop/the hive/start.png");
    ui->label_pic->setPixmap(pix);
    QPixmap pix1("C:/Users/admin/Desktop/hot.png");
    ui->label_hotel->setPixmap(pix1);
    QPixmap pix2("C:/Users/admin/Desktop/plane.png");
    ui->label_billet->setPixmap(pix2);
    QPixmap pix3("C:/Users/admin/Desktop/guide.png");
    ui->label_guide->setPixmap(pix3);
    QPixmap pix4("C:/Users/admin/Desktop/transport.png");
    ui->label_transport->setPixmap(pix4);*/

}

menu_agent::~menu_agent()
{
    delete ui;
}
//******************************* ESAYED IL MASSOUSSI**************************************

void menu_agent::on_pb_ajouter_clicked()
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
   {
         ui->tabreservation_2->setModel(tmpreservation.afficher());//refresh
   QMessageBox::information(nullptr, QObject::tr("Ajouter une reservation"),
                     QObject::tr("reservation ajouté.\n" "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else
         QMessageBox::critical(nullptr, QObject::tr("Ajouter une reservation"),
                     QObject::tr("Erreur !.\n" "Click Cancel to exit."), QMessageBox::Cancel);

}


void menu_agent::on_pb_supprimer_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    int num= ui->lineEdit_num_billet->text().toInt();
    bool test=tmpreservation.supprimer(id);

    bool test1=tmpbillet.supprimer(num);
    if( test&&test1)
    {

        ui->tabbillet->setModel(tmpbillet.afficher()) ;
        ui->tabreservation_2->setModel(tmpreservation.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un reservation"),QObject::tr("reservation supprimé.\n""Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un reservation"),QObject::tr("Erreur !.\n""Click Cancel to exit."), QMessageBox::Cancel);
}
void menu_agent::update_label()
{
    data=A.read_from_arduino();

}

void menu_agent::on_mise_a_jour_clicked()
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
   {ui->tabreservation_2->setModel(tmpreservation.afficher());//refresh
   QMessageBox::information(nullptr, QObject::tr("Ajouter une reservation"),
                     QObject::tr("reservation updated.\n" "Click Cancel to exit."), QMessageBox::Cancel);
    A.write_to_arduino("1"); //envoyer 1 à arduino


   }
     else
         QMessageBox::critical(nullptr, QObject::tr("Ajouter une reservation"),
                     QObject::tr("Erreur !.\n" "Click Cancel to exit."), QMessageBox::Cancel);
      A.write_to_arduino("0"); //envoyer 1 à arduino


}


void menu_agent::on_afficher_clicked()
{
    ui->tabbillet->setModel(tmpbillet.afficher());
    ui->tabWidget_4->show();
    //  ui->tabreserversation_3->hide();
      ui->tabreservation_2->show();
      ui->tabreservation_2->setModel(tmpreservation.afficher());
}

void menu_agent::on_checkBox_guide_toggled(bool checked)
{
    ui->frame_guide->setEnabled(1);


}

void menu_agent::on_checkBox_3_toggled(bool checked)
{
      ui->frame_hotel->setEnabled(1);
}


void menu_agent::on_checkBox_billet_toggled(bool checked)
{
    ui->frame_billet->setEnabled(1) ;

}
//rechercher


void menu_agent::on_rechercher_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
        // ui->tabreservation_2->hide();
         //ui->tabreserversation_3->show();
    ui->tabreservation_2->show();

          ui->tabreservation_2->setModel(tmpreservation.rechercher(id));//refresh

}

void menu_agent::on_trier_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    ui->tabreservation_2->setModel(tmpreservation.tri_affiche());//refresh

}
//***************************RANA**************************************

//client

void menu_agent::on_pushButton_2_clicked()
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

void menu_agent::on_refresh_clicked()
{
   /* client *p=new client();
        ui->table_afficher->setModel(p->getAllclient());*/
    ui->table_afficher->setModel(c.afficher_client());//refresh

}

void menu_agent::on_pushButton_clicked()
{
    int id = ui->lineEdit_9->text().toInt();
        bool test=c.supprimer_client(id);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                        QObject::tr(" client supprime .\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
             ui->table_afficher->setModel(c.afficher_client());//refresh

        }
        else
        {QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}

}

void menu_agent::on_pushButton_6_clicked()
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
       ui->table_afficher->setModel(c.tri());
}


void menu_agent::on_pushButton_4_clicked()
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
         A.write_to_arduino("1"); //envoyer 0 à arduino
        }
     else { A.write_to_arduino("0");} //envoyer 1 à arduino
}


void menu_agent::on_table_afficher_activated(const QModelIndex &index)
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

//transport


void menu_agent::on_checkBox_billet_stateChanged(int arg1)
{

}

void menu_agent::on_pushButton_3_clicked()
{
    int id = ui->lineEdit_9->text().toInt();
         ui->tableView_4->setModel(c.recherchernomclient(id));
}

void menu_agent::on_pushButton_5_clicked()
{

}

void menu_agent::on_client_widget_currentChanged(int index)
{

    int id2 = ui->lineEdit_32->text().toInt();
     int numtaxi = ui->lineEdit_30->text().toInt();
      int numchauffeure= ui->lineEdit_29->text().toInt();
    QString pointdepart= ui->lineEdit_13->text();
    QString pointarriv= ui->lineEdit_34->text();
     QString datedepart= ui->lineEdit_33->text();
     QString heureudepart= ui->lineEdit_31->text();
  Transport T(id2,pointdepart,pointarriv,datedepart,heureudepart,numtaxi,numchauffeure);


}

void menu_agent::on_pushButton_7_clicked()
{
      ui->table_afficher_2->setModel(T.afficher_Transport());
}
void menu_agent::shootscreen()
{
    //capture the screen shot
        QScreen *screen= QGuiApplication::primaryScreen();
        QPixmap map =screen->grabWindow(0);
        bool result =map.save("C:/Users/NOUR/Desktop/test.jpg","JPG");
}

void menu_agent::on_pushButton_17_clicked()
{
   QTimer::singleShot(500,this,& menu_agent::shootscreen);
}

void menu_agent::on_pushButton_19_clicked()
{
    ui->table_afficher_2->setModel(T.tri());

}

void menu_agent::on_pushButton_20_clicked()
{
    int id2 = ui->lineEdit_11->text().toInt();
       bool test=T.supprimer_Transport(id2);
       if(test)
       { ui->table_afficher_2->setModel(T.afficher_Transport());
           ui->tableView_5->setModel(T.afficher_Transport());


           QMessageBox::information(nullptr, QObject::tr("Supprimer transport"),
                       QObject::tr("transport supprime.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else
           QMessageBox::critical(nullptr, QObject::tr("Supprimer transport"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}

void menu_agent::on_pushButton_21_clicked()
{

             int id2 = ui->lineEdit_8->text().toInt();
                  ui->tableView_5->setModel(T.rechercherid2(id2));

}

void menu_agent::on_pushButton_18_clicked()
{
    int id2 = ui->lineEdit_32->text().toInt();
         int numtaxi = ui->lineEdit_30->text().toInt();
          int numchauffeure= ui->lineEdit_29->text().toInt();
        QString pointdepart= ui->lineEdit_13->text();
        QString pointarriv= ui->lineEdit_34->text();
         QString datedepart= ui->lineEdit_33->text();
         QString heureudepart= ui->lineEdit_31->text();
      Transport T(id2,pointdepart,pointarriv,datedepart,heureudepart,numtaxi,numchauffeure);

     if(ui->lineEdit_32->text().isEmpty() || ui->lineEdit_30->text().isEmpty() || ui->lineEdit_29->text().isEmpty() || ui->lineEdit_13->text().isEmpty() || ui->lineEdit_34->text().isEmpty() || ui->lineEdit_33->text().isEmpty() || ui->lineEdit_31->text().isEmpty())
     {

             QMessageBox::warning(nullptr, QObject::tr("Ajouter transport"),
                               QObject::tr("veuillez remplir tous les champs.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);




     } else
     {
      bool test=T.ajoutercTransport();
      if(test)
    {
        ui->table_afficher_2->setModel(T.afficher_Transport());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter transport "),
                      QObject::tr("Transport ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
      } }
}
