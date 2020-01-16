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
#include"conge.h"
#include"personnel.h"
#include "menu_com.h"
#include "mainwindow.h"
#include <QPieSeries>
#include <QChart>
#include <QChartView>
#include "contrat.h"
#include"partenaire.h"




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
void menu_agent::shootscreen()
{
     //capture the screen shot
     QScreen *screen = QGuiApplication::primaryScreen();

     QPixmap map =screen->grabWindow(0);
     bool result = map.save("C:/Users/NOUR/Desktop/test1.jpg", "JPG");
}
void menu_agent::on_screen_clicked()
{
    QTimer::singleShot(500, this, &menu_agent::shootscreen);
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
void menu_agent::shootscreen1()
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


//********************************************** nalouti*****************************************
void menu_agent::on_pushButton_perso1_2_clicked()
{
    QString nom= ui->nom_perso_2->text();
           QString prenom= ui->prenom_perso_2->text();
     int ID= ui->id_perso_2->text().toInt();
      int CIN= ui->cin_perso_2->text().toInt();
      personnel p(CIN,ID,nom,prenom);
      bool test=p.ajouter();
    A.write_to_arduino("1");
      if(test)
      {  A.write_to_arduino("3");
          QMessageBox::critical(nullptr,QObject::tr("Ajout avec succes"),
                              QObject::tr("connection successful\n ""Click cancel to exite "),QMessageBox::Cancel);
        //  Dialog D;
         // D.exec();

      }
      else
      { QMessageBox::critical(nullptr,QObject::tr("Ajout!!!!"),
                              QObject::tr("noooo\n ""Click cancel to exite "),QMessageBox::Cancel);

      }
}

void menu_agent::on_pushButton_8_clicked()
{
    QSqlQuery query;
        ui->listWidget_2->clear();
        query.exec("select * from PERSONNEL ORDER BY ID DESC");
        while(query.next())
        {

         QString id=query.value(0).toString();
         QString nom=query.value(1).toString();
         QString prenom=query.value(2).toString();
         QString cin=query.value(3).toString();
         QString ch=id+"                                                   "+nom+"                                                   "+prenom+"                                                   "+cin;
         ui->listWidget_2->addItem(ch);

        }
}

void menu_agent::on_pushButton_modifier_3_clicked()
{
    QSqlQuery query;
                QString cin = ui->cin_11->text();
                QString nom=ui->nom_11->text();
                QString prenom=ui->prenom_11->text();
                query.prepare("update PERSONNEL set prenom=:prenom ,nom=:nom WHERE CIN =:cin");
                query.bindValue(":prenom",prenom);
                query.bindValue(":nom",nom);
                query.bindValue(":cin",cin);

                bool t=query.exec();
                       if(t)
                       {A.write_to_arduino("1");
                       QMessageBox::information(nullptr, QObject::tr("Modifier"),
                                       QObject::tr("personnel modifié.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);


                       }
                       else
                          {A.write_to_arduino("0");
                           QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                                       QObject::tr("Erreur !.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void menu_agent::on_chercher_2_textChanged(const QString &arg1)
{
    ui->listWidget_6->clear();
            QSqlQuery query;
            //query.prepare("SELECT * from PERSONNEL where CIN=:nombre");
            query.prepare("SELECT * from PERSONNEL where substr(to_char(CIN),1,:size) like :nombre");
            query.bindValue(":nombre",arg1);
            query.bindValue(":size",arg1.size());
            query.exec();
            while(query.next())
            {
                QString id=query.value(0).toString();
                QString nom=query.value(1).toString();
                QString prenom=query.value(2).toString();
                QString cin=query.value(3).toString();
                QString ch=id+"                                              "+id+"                                              "+nom+"                                              "+prenom+"                      "+cin;
                ui->listWidget_6->addItem(ch);

            }
}

void menu_agent::on_Ajouter_conge_clicked()
{
    int id_conge= ui->cin_8->text().toInt();
         int id_personnel= ui->id_personnel->text().toInt();
           QString debut_conge= ui->debut_conge->text();
           QString fin_conge= ui->fin_conge->text();


      conge c(id_conge,debut_conge,fin_conge,id_personnel);
      bool test=c.ajouter();
    A.write_to_arduino("1");
      if(test)
      {  A.write_to_arduino("3");

          ui->tableView->setModel(C.afficher());//refresh
          QMessageBox::critical(nullptr,QObject::tr("Ajout avec succes"),
                              QObject::tr("conge ajouté\n ""Click cancel to exite "),QMessageBox::Cancel);


      }
      else
      { QMessageBox::critical(nullptr,QObject::tr("Ajout!!!!"),
                              QObject::tr("noooo\n ""Click cancel to exite "),QMessageBox::Cancel);

      }

}

void menu_agent::on_pushButton_22_clicked()
{
    QSqlQuery query;
            int val = ui->lineEdit_12->text().toInt();
            int id=ui->lineEdit_10->text().toInt();
                QString debut=ui->lineEdit_14->text();
                QString fin=ui->lineEdit_35->text();
                C.modifier(id,debut,fin,val);

                       if(query.exec())
                       {A.write_to_arduino("1");
                            ui->tableView->setModel(C.afficher());//refresh
                       QMessageBox::information(nullptr, QObject::tr("Modifier"),
                                       QObject::tr("personnel modifié.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);


                       }
                       else
                          {A.write_to_arduino("0");
                           QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                                       QObject::tr("Erreur !.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void menu_agent::on_pushButton_supprimer_3_clicked()
{
    {

            int cin = ui->lineEdit_8->text().toInt();
                QSqlQuery query;
                query.prepare("delete from PERSONNEL where CIN= :nombre");
                query.bindValue(":nombre",cin);
                bool v=query.exec();
                A.write_to_arduino("0");
                if(v)
                {

                        ui->listWidget_2->clear();

                        while(query.next())
                        {

                         QString id=query.value(0).toString();
                         QString nom=query.value(1).toString();
                         QString prenom=query.value(2).toString();
                         QString cin=query.value(3).toString();
                         QString ch =id+"                                               "+nom+"                                               "+prenom+"                                              "+cin;
                         ui->listWidget_2->addItem(ch);

                        }
                QMessageBox::information(nullptr, QObject::tr("Supprimer un personnel"),
                                QObject::tr("pe"
                                            "PErsonnel supprimé.\n"
                                            "Click Cancel to exitS."), QMessageBox::Cancel);

                }
                else{
                    QMessageBox::critical(nullptr, QObject::tr("personnel n'existe pas !"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
        }
        }
}

void menu_agent::on_pushButton_23_clicked()
{
     QSqlQuery query;
   ui->listWidget_2->clear();
   QString id=query.value(1).toString();
       QString nom=query.value(0).toString();
       QString prenom=query.value(2).toString();
       QString cin=query.value(3).toString();

   QString ch=nom+"                                                   "+id+"                                                   "+prenom+"                                                   "+cin;
       ui->listWidget_2->addItem(ch);

}



void menu_agent::on_pushButton_24_clicked()
{
   // MainWindow MainWindow;
   // this->hide();
    /*this->hide();
   menu_com menu;
  menu.setModal(true);

   menu.exec(); */

}

void menu_agent::on_pushButton_25_clicked()
{
  /*  QPieSeries * series = new QPieSeries() ;
 int on= 0 ;
 int off = 0 ;
    QSqlQuery query;
               query.prepare("select * from PERSONNEL ");
               query.exec();
               while(query.next())
               {
                   if  ((query.value(0).toInt())>100 ) { on++ ; }
                   if  ((query.value(0).toInt())<100 ) { off++ ; }

               }
               series->append("ID > 100 ",on);

               series->append("ID < 100",off);
               series->setLabelsVisible();


      QChart *chart = new QChart();
      chart->addSeries(series);
      chart->setTitle("ID");
      QChartView *chartView = new QChartView(chart);
      chartView->setRenderHint(QPainter::Antialiasing);
      ui->horizontalLayout->addWidget(chartView);*/
}
//****************** reine*********************

void menu_agent::on_pushButton_13_clicked()
{
    Partenaire p;

    qDebug()<<"Le Bouton Envoyer a ete appuie..."<<endl;

    p.SetId(ui->IdAjoutPartenaire->text().toULong());
    p.SetNom(ui->NomAjout->text());
    p.SetAdresse(ui->AdresseAjout->text());
    p.SetMail(ui->MailAjout->text());
    p.SetType(ui->TypeAjout->text());
    p.SetId_contrat(ui->IdcontratAjout->text().toULong());

    QSqlQuery query;

    query.prepare("INSERT INTO PARTENAIRE (ID, NOM, ADRESSE, MAIL, ID_CONTRAT,TYPE)"
                            "VALUES (: ID, : NOM, : ADRESSE, : MAIL ,: ID_CONTRAT, :TYPE)");

    query.addBindValue(p.getId());
    query.addBindValue(p.getNom());
    query.addBindValue(p.getAdresse());
    query.addBindValue(p.getMail());
    query.addBindValue(p.getType());
    query.addBindValue(p.getId_contrat());
    query.exec();
    if(query.exec())
        A.write_to_arduino("1");
    else
        A.write_to_arduino("0");
    //afficher
    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery query2;
    query2.prepare("SELECT * FROM PARTENAIRE ")  ;
    query2.exec() ;
    model->setQuery(query2);
    ui->afficherPaternaire-> setModel(model);
    qDebug()<<"Envoi effectue"<<endl;
}


void menu_agent::on_pushButton_10_clicked()
{
    //modif
    Contrat c ;
    qDebug()<<"Le Bouton Envoyer a ete appuie..."<<endl;

    c.SetId_contrat(ui->idContrats->text().toULong());
    c.SetDate_debut_contrat(ui->dateDebutContrats->text());
    c.SetDate_fin_contrat(ui->dateFinContrats->text());



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
    ui->afficherContrats-> setModel(model);
    qDebug()<<"Envoi effectue"<<endl;
}

void menu_agent::on_pushButton_11_clicked()
{
    Contrat c;
    QSqlQuery query;
    int id;
    c.SetId_contrat(ui->idSuppContrats->text().toULong());
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
        ui->afficherContrats-> setModel(model);
    }
    else
    {
        std::cout << "Suppri:( Une erreur s'est produite. :(" << std::endl << q2c(query.lastError().text()) << std::endl;
    }
}

void menu_agent::on_pushButton_12_clicked()
{
    //trier

    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery query2;
    query2.prepare("SELECT * FROM CONTRAT order by id asc");
    query2.exec() ;
    model->setQuery(query2);
    ui->afficherContrats-> setModel(model);

}

void menu_agent::on_idContratsRechercher_textChanged(const QString &arg1)
{
    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery query2;
    query2.prepare("SELECT * FROM contrat where ID_CONTRAT like :test ")  ;
    query2.bindValue(":test",arg1+"%");
    query2.exec() ;
    model->setQuery(query2);
    ui->afficherContrats-> setModel(model);
}

void menu_agent::on_pushButton_14_clicked()
{
    //modifier
    Partenaire p;
    QSqlQuery query;
    p.SetNom(ui->NomAjout->text());
    p.SetId(ui->IdAjoutPartenaire->text().toULong());
    p.SetAdresse(ui->AdresseAjout->text());
    p.SetMail(ui->MailAjout->text());
    p.SetType(ui->TypeAjout->text());
    p.SetId_contrat(ui->IdcontratAjout->text().toInt());
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
        ui->afficherPaternaire-> setModel(model);
    }
    else
    {
        std::cout << "Modif:( Desolé une erreur s'est produite. :(" << std::endl << q2c(query.lastError().text()) << std::endl;
    }
}

void menu_agent::on_pushButton_15_clicked()
{
    //supprimer
    Partenaire p;
    QSqlQuery query;
    int id;
    p.SetId(ui->id_PartenaireSupp->text().toULong());
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
        ui->afficherPaternaire-> setModel(model);
    }
    else
    {
        std::cout << "Suppri:( Une erreur s'est produite. :(" << std::endl << q2c(query.lastError().text()) << std::endl;
    }
}

void menu_agent::on_pushButton_16_clicked()
{
    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery query2;
    query2.prepare("SELECT * FROM partenaire order by nom asc")  ;
    query2.exec() ;
    model->setQuery(query2);
    ui->afficherPaternaire-> setModel(model);
}

void menu_agent::on_pushButton_26_clicked()
{
    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery query2;
    query2.prepare("SELECT * FROM partenaire order by type asc")  ;
    query2.exec() ;
    model->setQuery(query2);
    ui->afficherPaternaire-> setModel(model);
}

void menu_agent::on_lineEdit_28_textChanged(const QString &arg1)
{
    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery query2;
    query2.prepare("SELECT * FROM partenaire where nom like :test ")  ;
    query2.bindValue(":test",arg1+"%");
    query2.exec() ;
    model->setQuery(query2);
    ui->afficherPaternaire-> setModel(model);
}

void menu_agent::on_pushButton_27_clicked()
{
    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery query2;
    query2.prepare("SELECT TYPE, COUNT(*) FROM partenaire group by type");
    query2.exec() ;
    model->setQuery(query2);
    ui->afficherPaternaire-> setModel(model);
}

void menu_agent::on_pushButton_9_clicked()
{
    Contrat c ;
    qDebug()<<"Le Bouton Envoyer a ete appuie..."<<endl;

    c.SetId_contrat(ui->idContrats->text().toInt());
    c.SetDate_debut_contrat(ui->dateDebutContrats->text());
    c.SetDate_fin_contrat(ui->dateFinContrats->text());



    QSqlQuery query;

    query.prepare("INSERT INTO CONTRAT ( DATE_DEBUT_CONTRAT,ID_CONTRAT, DATE_FIN_CONTRAT)"
                            "VALUES ( :DATE_DEBUT_CONTRAT,:ID_CONTRAT,:DATE_FIN_CONTRAT)");

    query.addBindValue(c.getId_contrat());
    query.addBindValue(c.getDate_debut_contrat());
    query.addBindValue(c.getDate_fin_contrat());

    query.exec();
    if(query.exec())
        A.write_to_arduino("1");
    else
        A.write_to_arduino("0");
    //afficher
    QSqlQueryModel * model=new QSqlQueryModel() ;
    QSqlQuery query2;
    query2.prepare("SELECT * FROM CONTRAT ")  ;
    query2.exec() ;
    model->setQuery(query2);
    ui->afficherContrats-> setModel(model);
    qDebug()<<"Envoi effectue"<<endl;
}
