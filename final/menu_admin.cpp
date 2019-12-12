#include "menu_admin.h"
#include "ui_menu_admin.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QPixmap>
#include <QDesktopServices>
#include "depenses.h"
#include "salaire.h"
#include "revenu.h"
#include "arduino.h"
#include "notif.h"
#include <QTextDocument>
#include <QPrinter>
#include <QPrintDialog>

menu_admin::menu_admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu_admin)
{
    ui->setupUi(this);
    ui-> tableView_affich_dep ->setModel(dep.afficher_depense());
    ui-> tableView_affich_sal ->setModel(sal.afficher_salaire());
    ui->tableView_affich_rev->setModel(rev.afficher_revenu());
    ui->tableView_modif_sal ->setModel(sal.tri_affiche());
    ui-> tableView_modif_dep ->setModel(dep.tri_depense());
    ui->tableView_modif_rev->setModel(rev.tri_revenu());

}

menu_admin::~menu_admin()
{
    delete ui;
}

void menu_admin::on_pushButton_ajou_dep_clicked()
{
    int  id = ui->lineEdit_ajout_id_dep->text().toInt();
     QString type= ui->lineEdit_ajout_type_dep -> text();

      float tva = ui->lineEdit_ajout_tva->text().toFloat();
     float s =ui->lineEdit_ajout_montant_dep->text().toFloat();
     // QString perso=ui->lineEdit_ajout_perso -> text();
     //QString type= dep.get_type_depenses();

   // QMessageBox::information(this,"Login",dep.get_type_depenses());

    Depenses dep (id,type,tva,s);

    bool test=dep.ajouter_depense();
    if(test)
  {ui->tableView_affich_dep->setModel(dep.afficher_depense());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter une depense "),
                    QObject::tr("depense ajouté.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
    { QMessageBox::warning(this,"depense","depense non ajoutee");}
}


void menu_admin::on_pushButton_tri_dep_clicked()
{
    ui->tableView_affich_dep ->setModel(dep.tri_depense());//refresh
}





void menu_admin::on_pushButton_ajout_rev_clicked()
{
    float net=0;
    float encaiss=0;
    float total=0;
    int id_dep=0;
    int  id = ui->lineEdit_ajout_id_rev->text().toInt();
     QString type= ui->lineEdit_ajout_type_rev-> text();
     float facture= ui->lineEdit_ajout_facture-> text().toFloat();
      float achat = ui->lineEdit_ajout_achat->text().toFloat();

     //QString type= dep.get_type_depenses();

   // QMessageBox::information(this,"Login",dep.get_type_depenses());

Revenu rev (id,net,type,facture,achat,encaiss,total,id_dep);


    bool test=rev.ajouter_revenu();
    if(test)
  {ui->tableView_affich_rev->setModel(rev.afficher_revenu());//refresh
   ui-> tableView_modif_rev ->setModel(rev.afficher_revenu());//refrech modif
  QMessageBox::information(nullptr, QObject::tr("Ajouter un revenu "),
                    QObject::tr("revenu ajouté.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
    { QMessageBox::warning(this,"revenu","revenu non ajouté");}
}

void menu_admin::on_pushButton_ajout_sal_clicked()
{
    int  id = ui->lineEdit_ajout_id_sal->text().toInt();
     QDate vers= ui->dateEdit_ajout_vers-> date();
     QDate modif= ui->dateEdit_ajout_modif-> date();
      float mont = ui->lineEdit_ajout_montant_sal->text().toFloat();
     float sanc=0;
     float promo=0;
     QString nom_perso=ui->lineEdit_ajout_nomperso_sal->text();


     //QString type= dep.get_type_depenses();

   // QMessageBox::information(this,"Login",dep.get_type_depenses());

    Salaire sal (id,vers,modif,mont,sanc,promo,nom_perso);

    bool test=sal.ajouter_salaire();
    if(test)
  {ui->tableView_affich_sal->setModel(sal.afficher_salaire());//refresh
        ui->tableView_modif_sal ->setModel(sal.tri_affiche());//refrech modif

  QMessageBox::information(nullptr, QObject::tr("Ajouter un salaire "),
                    QObject::tr("salaire ajouté.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
  QString okd="";
                       notif ok;
                       ok.notification_Ouverture(okd);

  }
    else
    { QMessageBox::warning(this,"salaire","salaire non ajouté");}
}

void menu_admin::on_pushButton_tri_rev_clicked()
{
    ui->tableView_affich_sal->setModel(rev.tri_revenu());//refresh
}

void menu_admin::on_pushButton_tri_sal_clicked()
{
    ui->tableView_affich_sal->setModel(sal.tri_affiche());//refresh
}

void menu_admin::on_lineEdit_cherch_perso_textChanged(const QString &arg1)
{
    QString nom ;
   QSqlQuery  query;


           query.prepare("select * from SALAIRE where NOM_PERSONNEL LIKE '%"+ui->lineEdit_cherch_perso->text()+"%'");

           sal.recherche_salaire(query);
           query.addBindValue("%"+nom+"%");
           query.exec();
        //  query.next();

          // ui->lineEdit_cherch->setText(q.value(7).toString());
          // ui->lineEdit_cherch->setText(q.value(2).toString());
//sal.recherche_salaire(query);
ui->tableView_modif_sal->setModel(sal.recherche_salaire(query));//refresh
}


void menu_admin::on_lineEdit_supp_rev_textChanged(const QString &arg1)
{
    int id;
    QSqlQuery  query;


            query.prepare("select * from REVENU where ID_REVENU LIKE '%"+ui->lineEdit_supp_rev->text()+"%'");

            rev.recherche_revenu(query);
            query.addBindValue("%+id+%");
            query.exec();
         //  query.next();

           // ui->lineEdit_cherch->setText(q.value(7).toString());
           // ui->lineEdit_cherch->setText(q.value(2).toString());
 //sal.recherche_salaire(query);
 ui->tableView_modif_rev->setModel(rev.recherche_revenu(query));//refresh
}


void menu_admin::on_lineEdit_supp_dep_textChanged(const QString &arg1)
{
    int id;
    QSqlQuery  query;


            query.prepare("select * from DEPENSES where ID_DEPENSE LIKE '%"+ui->lineEdit_supp_dep->text()+"%'");

           dep.recherche_depense(query);
            query.addBindValue("%+id+%");
            query.exec();
         //  query.next();

           // ui->lineEdit_cherch->setText(q.value(7).toString());
           // ui->lineEdit_cherch->setText(q.value(2).toString());
 //sal.recherche_salaire(query);
 ui->tableView_modif_dep->setModel(dep.recherche_depense(query));//refresh
}

void menu_admin::on_tableView_modif_dep_activated(const QModelIndex &index)
{
    QString val=ui->tableView_modif_dep->model()->data(index).toString();
     QSqlQuery  query;
     query.prepare("select * from DEPENSES where ID_DEPENSE='"+val+"'");

     if(query.exec())
     {
         while (query.next())
         {
             ui->lineEdit_supp_dep->setText(query.value(0).toString());
             ui->lineEdit_modif_type_dep->setText(query.value(1).toString());
             ui->lineEdit_modif_tva->setText(query.value(2).toString());
             ui->lineEdit_modif_montant_dep->setText(query.value(3).toString());

         }
     }
         else  {QMessageBox::warning(this,"depense","erreur");}
}
void menu_admin::on_pushButton_modif_dep_clicked()
{
    QSqlQuery q;

     QString val=ui->lineEdit_supp_dep->text();

    q.prepare("update DEPENSES set TYPE_DEPENSE=:type_depense,TAUX_TVA=:taux_TVA,SOMME=:somme  WHERE ID_DEPENSE='"+val+"'" );

    q.bindValue(":type_depense",ui->lineEdit_modif_type_dep->text());
    q.bindValue(":taux_TVA",ui->lineEdit_modif_tva->text());
    q.bindValue(":somme",ui->lineEdit_modif_montant_dep->text());
    ui-> tableView_affich_dep ->setModel(dep.afficher_depense());//refresh

       if(q.exec())
       {
            ui-> tableView_affich_dep ->setModel(dep.afficher_depense());//refresh
            ui-> tableView_modif_dep ->setModel(dep.afficher_depense());//refrech modif
           QMessageBox msgBox ;
                   msgBox.setText("la Depense a ete modifiee ");
                   msgBox.exec();
                   A.write_to_arduino("1"); //envoyer 0 à arduino

       }
       else {
           QMessageBox msgBox ;
                   msgBox.setText("la Depense n'est pas modifiee");
                   msgBox.exec();
                   A.write_to_arduino("0"); //envoyer 0 à arduino

       }
}


void menu_admin::on_pushButton_supp_dep_clicked()
{
    int  id =ui->lineEdit_supp_dep->text().toInt();
     bool test=dep.supprimer_depense(id);
     if(test)
     {ui->tableView_affich_dep->setModel(dep.afficher_depense());//refresh
         QMessageBox::information(nullptr, QObject::tr("Supprimer une depense"),
                     QObject::tr("depense supprimé.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
         QString okd="";
                              notif ok;
                              ok.notification_sup_produit(okd);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Supprimer une depense"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void menu_admin::on_tableView_modif_rev_activated(const QModelIndex &index)
{
    QString val=ui->tableView_modif_rev->model()->data(index).toString();
     QSqlQuery  query;
     query.prepare("select * from REVENU where ID_REVENU='"+val+"'");

     if(query.exec())
     {
         while (query.next())
         {
             ui->lineEdit_supp_rev->setText(query.value(0).toString());
             ui->lineEdit_modif_type_rev->setText(query.value(2).toString());
             ui->lineEdit_modif_facture->setText(query.value(3).toString());
             ui->lineEdit_modif_achat->setText(query.value(4).toString());

         }
     }
         else  {QMessageBox::warning(this,"revenu","erreur");}
}

void menu_admin::on_pushButton_modif_rev_clicked()
{
    QSqlQuery q;
     QString val=ui->lineEdit_supp_rev->text();
     QString res5= QString :: number ( rev.calculer_encaissement());
       q.prepare("update REVENU set TYPE_REVENU=:TYPE_REVENU,PRIX_FACTURE=:PRIX_FACTURE,PRIX_ACHAT=:PRIX_ACHAT,ENCAISSEMENT=:ENCAISSEMENT where ID_REVENU='"+val+"'" );
       q.bindValue(":TYPE_REVENU",ui->lineEdit_modif_type_rev->text());
       q.bindValue(":PRIX_FACTURE",ui->lineEdit_modif_facture->text());
       q.bindValue(":PRIX_ACHAT",ui->lineEdit_modif_achat->text());
      //  rev.calculer_encaissement();
       q.bindValue(":ENCAISSEMENT",res5);



       if(q.exec())
       {
           ui->tableView_affich_rev->setModel(rev.afficher_revenu());//refresh
            ui-> tableView_modif_rev ->setModel(rev.afficher_revenu());//refrech modif

           QMessageBox msgBox ;
                   msgBox.setText("la revenu a ete modifiee ");
                   msgBox.exec();
                   A.write_to_arduino("1"); //envoyer 0 à arduino

       }
       else {
           QMessageBox msgBox ;
                   msgBox.setText("la revenu n'est pas modifiee");
                   msgBox.exec();
                   A.write_to_arduino("0"); //envoyer 0 à arduino

       }
}

void menu_admin::on_pushButton_supp_rev_clicked()
{
    int  id = ui->lineEdit_supp_rev->text().toInt();
     bool test=rev.supprimer_revenu(id);
     if(test)
     {
         ui->tableView_affich_rev->setModel(rev.afficher_revenu());//refresh
         ui-> tableView_modif_rev ->setModel(rev.afficher_revenu());//refrech modif
         QMessageBox::information(nullptr, QObject::tr("Supprimer un revenu"),
                     QObject::tr("revenu supprimé.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
         QString okd="";
                              notif ok;
                              ok.notification_sup_produit(okd);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un revenu"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void menu_admin::on_tableView_modif_sal_activated(const QModelIndex &index)
{
    QString val=ui->tableView_modif_sal->model()->data(index).toString();
     QSqlQuery  query;
     query.prepare("select * from SALAIRE where ID_SALAIRE='"+val+"'");

     if(query.exec())
     {
         while (query.next())
         {
             ui->lineEdit_cherch_perso_2->setText(query.value(0).toString());
             ui->dateEdit_modif_vers->setDate(query.value(1).toDate());
             ui->dateEdit_modif_modif->setDate(query.value(2).toDate());
             ui->lineEdit_modif_sanc->setText(query.value(4).toString());
             ui->lineEdit_modif_promo->setText(query.value(5).toString());
             ui->lineEdit_montant_sal->setText(query.value(3).toString());
             ui->lineEdit_modif_perso->setText(query.value(6).toString());
             ui->lineEdit_cherch_perso->setText(query.value(6).toString());

         }
     }
         else  {QMessageBox::warning(this,"salaire","erreur");}
}

void menu_admin::on_pushButton_modif_sal_clicked()
{
    QString val=ui->lineEdit_cherch_perso_2->text();
   QSqlQuery q;
      sal.ajouter_sanction();
      sal.ajouter_promotion();


      q.prepare("update SALAIRE set  DATE_VERSEMENT=:DATE_VERSEMENT,DATE_MODIF=:DATE_MODIF,MONTANT_SALAIRE=:MONTANT_SALAIRE,SANCTION=:SANCTION,PROMOTION=:PROMOTION,NOM_PERSONNEL=:NOM_PERSONNEL where ID_SALAIRE='"+val+"'" );
      q.bindValue(":DATE_VERSEMENT",ui->dateEdit_modif_vers->dateTime());
      q.bindValue(":DATE_MODIF",ui->dateEdit_modif_modif->dateTime());
      q.bindValue(":MONTANT_SALAIRE",ui->lineEdit_montant_sal->text());
      q.bindValue(":SANCTION",ui->lineEdit_modif_sanc->text());
      q.bindValue(":PROMOTION",ui->lineEdit_modif_promo->text());
        q.bindValue(":NOM_PERSONNEL",ui->lineEdit_modif_perso->text());


      //MONTANT_SALAIRE=:montant_salaire,
      if(q.exec())
      {
          ui->tableView_affich_sal->setModel(sal.afficher_salaire());//refresh
          ui->tableView_modif_sal ->setModel(sal.tri_affiche());//refrech modif
          QMessageBox msgBox ;
                  msgBox.setText("lE SALAIRE a ete modifiee ");
                  msgBox.exec();
                  A.write_to_arduino("1"); //envoyer 1 à arduino

      }
      else {
          QMessageBox msgBox ;
                  msgBox.setText("lE SALAIRE n'est pas modifiee");
                  msgBox.exec();
                  A.write_to_arduino("0"); //envoyer 0 à arduino

      }
}

void menu_admin::on_pushButton_supp_sal_clicked()
{
    int  id = ui->lineEdit_cherch_perso_2->text().toInt();
     bool test=sal.supprimer_salaire(id);
     if(test)
     {
         ui-> tableView_affich_sal ->setModel(sal.afficher_salaire());//refrech
         ui->tableView_modif_sal ->setModel(sal.tri_affiche());//refrech modif
         QMessageBox::information(nullptr, QObject::tr("Supprimer un salaire"),
                     QObject::tr("salaire supprimé.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
         QString okd="";
                              notif ok;
                              ok.notification_sup_produit(okd);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un salaire"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);


}

void menu_admin::on_pushButton_mail_clicked()
{
    QString link="https://mail.google.com/mail/u/0/#inbox";
    QDesktopServices::openUrl(QUrl(link));
}

void menu_admin::on_pushButton_fb2_clicked()
{
    QString link="https://www.facebook.com/";
    QDesktopServices::openUrl(QUrl(link));
}

void menu_admin::on_pushButton_insta2_clicked()
{
    QString link="https://www.instagram.com/";
    QDesktopServices::openUrl(QUrl(link));
}

void menu_admin::on_pushButton_lkn2_clicked()
{
    QString link="https://www.linkedin.com/";
    QDesktopServices::openUrl(QUrl(link));
}
void  menu_admin::imprimer ()
{
    QString strStream;
                QTextStream out(&strStream);

                const int rowCount =ui->tableView_modif_rev->model()->rowCount();
                const int columnCount = ui->tableView_modif_rev->model()->columnCount();
                QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                out <<"<html>\n"
                      "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    << "<title>ERP - COMmANDE LIST<title>\n "
                    << "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<h1 style=\"text-align: center;\"><strong> ***LISTE DES agences *** "+TT+"</strong></h1>"
                    "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                      "</br> </br>";
                // headers
                out << "<thead><tr bgcolor=#d6e5ff>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tableView_modif_rev->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tableView_modif_rev->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tableView_modif_rev->isColumnHidden(column)) {
                            QString data =ui->tableView_modif_rev->model()->data(ui->tableView_modif_rev->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);

                QPrinter printer;

                QPrintDialog *baba = new QPrintDialog(&printer, NULL);
                if (baba->exec() == QDialog::Accepted) {
                    document->print(&printer);
                }

                delete document;
}
void menu_admin::on_pushButton_imprimer_clicked()
{
    imprimer();
}
void menu_admin::update_label()
{
    data=A.read_from_arduino();

}


