#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "depenses.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow)
{
ui->setupUi(this);
//QPixmap pix(":/img/img/start.png");
//int w=ui->tabWidge->width();
//int h=ui->tabWidge->height();
//ui->tabWidge->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

ui-> tableView_affich_depense ->setModel(dep.afficher_depense());
ui-> tableView_salaire ->setModel(sal.afficher_salaire());
ui->tableView_affich_revenu->setModel(rev.afficher_revenu());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString id =ui-> lineEdit_id->text();

    QString mdp=ui-> lineEdit_mdp->text();

    if ((id == "admin" &&  mdp == "admin")||(id =="agent" && mdp == "agent") ||(id =="respcom" && mdp == "respcom") )
    {
         QMessageBox::information(this,"Login","id et mot de passe correct !");
    }

else {
       QMessageBox::warning(this,"Login","id et mot de passe incorrect !");
    }
}
/*QString MainWindow::on_checkBox_salaire_clicked()
{
    dep.get_type_depenses()="salaire";
     return dep.get_type_depenses();
}



QString MainWindow::on_checkBox_achat_clicked()
{
    dep.get_type_depenses()="achat";
     return dep.get_type_depenses();
}
*/



void MainWindow::on_pushButton_ajout_depense_clicked()
{
  int  id = ui->id_depense_2->text().toInt();
   QString type= ui->lineEdit_type_dep -> text();

    float tva = ui->taux_tva_2->text().toFloat();
   float s = ui->somme_2->text().toFloat();
   //QString type= dep.get_type_depenses();

 // QMessageBox::information(this,"Login",dep.get_type_depenses());

  Depenses dep (id,type,tva,s);

  bool test=dep.ajouter_depense();
  if(test)
{ui->tableView_affich_depense->setModel(dep.afficher_depense());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une depense "),
                  QObject::tr("depense ajouté.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
  { QMessageBox::warning(this,"depense","depense non ajoutee");}

}




void MainWindow::on_pushButton_supprimer_depense_clicked()
{

   int  id = ui->lineEdi_donner_id_depense->text().toInt();
    bool test=dep.supprimer_depense(id);
    if(test)
    {ui->tableView_affich_depense->setModel(dep.afficher_depense());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une depense"),
                    QObject::tr("depense supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une depense"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}










void MainWindow::on_pushButton_ajout_salaire_clicked()
{
    int  id = ui->lineEdit_id_salaire->text().toInt();
     QDateTime vers= ui->dateEdit_versement-> dateTime();
     QDateTime modif= ui->dateEdit_modif-> dateTime();
      float mont = ui->lineEdit_montant->text().toFloat();
     float sanc=0;
     float promo=0;
     QString nom_perso="nour";


     //QString type= dep.get_type_depenses();

   // QMessageBox::information(this,"Login",dep.get_type_depenses());

    salaire sal(id,vers,modif,mont,sanc,promo,nom_perso);

    bool test=sal.ajouter_salaire();
    if(test)
  {ui->tableView_salaire->setModel(sal.afficher_salaire());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un salaire "),
                    QObject::tr("salaire ajouté.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
    { QMessageBox::warning(this,"salaire","salaire non ajouté");}

}



void MainWindow::on_pushButton_supp_salaire_clicked()
{
    int  id = ui->lineEdit->text().toInt();
     bool test=sal.supprimer_salaire(id);
     if(test)
     {ui->tableView_salaire->setModel(sal.afficher_salaire());//refresh
         QMessageBox::information(nullptr, QObject::tr("Supprimer un salaire"),
                     QObject::tr("salaire supprimé.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un salaire"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}





void MainWindow::on_pushButton_ajouter_revenu_clicked()
{
    float net=0;
    float encaiss=0;
    float total=0;
    int id_dep=0;
    int  id = ui->lineEdit_id_revenu->text().toInt();
     QString type= ui->lineEdit_type_revenu-> text();
     float facture= ui->lineEdit_facture-> text().toFloat();
      float achat = ui->lineEdit_achat->text().toFloat();

     //QString type= dep.get_type_depenses();

   // QMessageBox::information(this,"Login",dep.get_type_depenses());

Revenu rev (id,net,type,facture,achat,encaiss,total,id_dep);


    bool test=rev.ajouter_revenu();
    if(test)
  {ui->tableView_affich_revenu->setModel(rev.afficher_revenu());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un revenu "),
                    QObject::tr("revenu ajouté.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
    { QMessageBox::warning(this,"revenu","revenu non ajouté");}

}

void MainWindow::on_pushButton_supp_revenu_clicked()
{
    int  id = ui->lineEdit_id_revenu->text().toInt();
     bool test=rev.supprimer_revenu(id);
     if(test)
     {
         ui->tableView_affich_revenu->setModel(rev.afficher_revenu());//refresh
         QMessageBox::information(nullptr, QObject::tr("Supprimer un revenu"),
                     QObject::tr("revenu supprimé.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un revenu"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_modif_sal_clicked()
{
    QSqlQuery q;
       sal.ajouter_sanction();
       sal.ajouter_promotion();


       q.prepare("update SALAIRE set  DATE_VERSEMENT=:date_versement,DATE_MODIF=:date_modification,MONTANT_SALAIRE=:montant_salaire,SANCTION=:sanction,PROMOTION=:promotion where ID_SALAIRE=:id_salaire" );
       q.bindValue(":id_salaire",ui->lineEdit_id_salaire_2->text());
       q.bindValue(":date_versement",ui->dateEdit_vers2->dateTime());
       q.bindValue(":date_modification",ui->dateEdit_modif2->dateTime());
       q.bindValue(":montant_salaire",ui->lineEdit_montant_2->text());
       q.bindValue(":sanction",ui->lineEdit_sanc->text());
       q.bindValue(":promotion",ui->lineEdit_promo->text());
       ui->tableView_salaire->setModel(sal.afficher_salaire());//refresh
       //MONTANT_SALAIRE=:montant_salaire,
       if(q.exec())
       {
           QMessageBox msgBox ;
                   msgBox.setText("lE SALAIRE a ete modifiee ");
                   msgBox.exec();

       }
       else {
           QMessageBox msgBox ;
                   msgBox.setText("lE SALAIRE n'est pas modifiee");
                   msgBox.exec();

       }

}

void MainWindow::on_pushButton_modif_dep_clicked()
{
    QSqlQuery q;
       q.prepare("update DEPENSES set  ID_DEPENSE=:id_depense,TYPE_DEPENSE=:type_depense,TAUX_TVA=:taux_TVA,SOMME=:somme" );
       q.bindValue(":id_depense",ui->id_depense_3->text());
       q.bindValue(":type_depense",ui->lineEdit_type_dep_2->text());
       q.bindValue(":taux_TVA",ui->taux_tva_3->text());
       q.bindValue(":somme",ui->somme_3->text());
       ui->tableView_affich_depense->setModel(dep.afficher_depense());//refresh

       if(q.exec())
       {
           QMessageBox msgBox ;
                   msgBox.setText("la Depense a ete modifiee ");
                   msgBox.exec();

       }
       else {
           QMessageBox msgBox ;
                   msgBox.setText("la Depense n'est pas modifiee");
                   msgBox.exec();

       }

}




void MainWindow::on_pushButton_modif_revenu_clicked()
{
    QSqlQuery q;

       q.prepare("update REVENU set  ID_REVENU=:id_revenu,TYPE_REVENU=:type_revenu,PRIX_FACTURE=:prix_facture,PRIX_ACHAT=:prix_achat,ENCAISSEMENT=:encaissement where   ID_REVENU=:id_revenu," );
       q.bindValue(":id_revenu",ui->lineEdit_id_revenu_2->text());
       q.bindValue(":type_revenu",ui->lineEdit_type_revenu_2->text());
       q.bindValue(":prix_facture",ui->lineEdit_facture_2->text());
       q.bindValue(":prix_achat",ui->lineEdit_facture_2->text());
      //  rev.calculer_encaissement();
       // q.bindValue(":encaissement",rev.calculer_);
        rev.update_encaissement();

      ui->tableView_affich_revenu->setModel(rev.afficher_revenu());//refresh

       if(q.exec())
       {
           QMessageBox msgBox ;
                   msgBox.setText("la revenu a ete modifiee ");
                   msgBox.exec();

       }
       else {
           QMessageBox msgBox ;
                   msgBox.setText("la revenu n'est pas modifiee");
                   msgBox.exec();

       }
}

void MainWindow::on_pushButton_trier_clicked()
{
    ui->tableView_salaire->setModel(sal.tri_affiche());//refresh
}



void MainWindow::on_lineEdit_cherch_textChanged(const QString &arg1)
{
    QString nom ;
   QSqlQuery  query;


           query.prepare("select * from SALAIRE where NOM_PERSONNEL LIKE '"+ui->lineEdit_cherch->text()+"'");

           sal.recherche_salaire(query);
           query.addBindValue("%"+nom+"%");
           query.exec();
        //  query.next();

          // ui->lineEdit_cherch->setText(q.value(7).toString());
          // ui->lineEdit_cherch->setText(q.value(2).toString());
//sal.recherche_salaire(query);
ui->tableView_recher->setModel(sal.recherche_salaire(query));//refresh
}
