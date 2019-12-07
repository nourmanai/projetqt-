#include "menuadmin.h"
#include "ui_menuadmin.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QPixmap>
#include "depenses.h"
#include "salaire.h"
#include "revenu.h"
menuadmin::menuadmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menuadmin)
{
    ui->setupUi(this);
    ui-> tableView_affich_dep ->setModel(dep.afficher_depense());
    ui-> tableView_affich_sal ->setModel(sal.afficher_salaire());
    ui->tableView_affich_rev->setModel(rev.afficher_revenu());
    ui->tableView_modif_sal ->setModel(sal.tri_affiche());
    ui-> tableView_modif_dep ->setModel(dep.tri_depense());
    ui->tableView_modif_rev->setModel(rev.tri_revenu());


}

menuadmin::~menuadmin()
{
    delete ui;
}

void menuadmin::on_pushButton_ajout_dep_clicked()
{
    int  id = ui->lineEdit_id_dep->text().toInt();
     QString type= ui->lineEdit_type_dep -> text();

      float tva = ui->lineEdit_tva->text().toFloat();
     float s =ui->lineEdit_montant->text().toFloat();
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


void menuadmin::on_pushButton_ajout_rev_clicked()
{
    float net=0;
    float encaiss=0;
    float total=0;
    int id_dep=0;
    int  id = ui->lineEdit_id_rev->text().toInt();
     QString type= ui->lineEdit_type_rev-> text();
     float facture= ui->lineEdit_facture_rev-> text().toFloat();
      float achat = ui->lineEdit_achat_rev->text().toFloat();

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

void menuadmin::on_pushButton_ajout_sal_clicked()
{
    int  id = ui->lineEdit_id_sal->text().toInt();
     QDate vers= ui->dateEdit_vers-> date();
     QDate modif= ui->dateEdit_modif-> date();
      float mont = ui->lineEdit_montant->text().toFloat();
     float sanc=0;
     float promo=0;
     QString nom_perso=ui->lineEdit_perso->text();


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

  }
    else
    { QMessageBox::warning(this,"salaire","salaire non ajouté");}
}


void menuadmin::on_pushButton_tri_dep_clicked()
{
    ui->tableView_affich_dep ->setModel(dep.tri_depense());//refresh
}

void menuadmin::on_pushButton_tri_rev_clicked()
{
    ui->tableView_affich_sal->setModel(rev.tri_revenu());//refresh
}

void menuadmin::on_pushButton_tri_sal_clicked()
{
    ui->tableView_affich_sal->setModel(sal.tri_affiche());//refresh
}


void menuadmin::on_lineEdit_cherch_perso_textChanged(const QString &arg1)
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

void menuadmin::on_lineEdit_supp_rev_textChanged(const QString &arg1)
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

void menuadmin::on_lineEdit_supp_dep_textChanged(const QString &arg1)
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

void menuadmin::on_tableView_modif_dep_activated(const QModelIndex &index)
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

void menuadmin::on_pushButton_modif_dep_clicked()
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

       }
       else {
           QMessageBox msgBox ;
                   msgBox.setText("la Depense n'est pas modifiee");
                   msgBox.exec();

       }

}

void menuadmin::on_pushButton_supp_dep_clicked()
{
    int  id =ui->lineEdit_supp_dep->text().toInt();
     bool test=dep.supprimer_depense(id);
     if(test)
     {ui->tableView_affich_dep->setModel(dep.afficher_depense());//refresh
         QMessageBox::information(nullptr, QObject::tr("Supprimer une depense"),
                     QObject::tr("depense supprimé.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Supprimer une depense"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void menuadmin::on_tableView_modif_rev_activated(const QModelIndex &index)
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
             ui->lineEdit_modif_facture_rev->setText(query.value(3).toString());
             ui->lineEdit_modif_achat_rev->setText(query.value(4).toString());

         }
     }
         else  {QMessageBox::warning(this,"revenu","erreur");}
}

void menuadmin::on_pushButton_modif_rev_clicked()
{

    QSqlQuery q;
     QString val=ui->lineEdit_supp_rev->text();
     QString res5= QString :: number ( rev.calculer_encaissement());
       q.prepare("update REVENU set TYPE_REVENU=:TYPE_REVENU,PRIX_FACTURE=:PRIX_FACTURE,PRIX_ACHAT=:PRIX_ACHAT,ENCAISSEMENT=:ENCAISSEMENT where ID_REVENU='"+val+"'" );
       q.bindValue(":TYPE_REVENU",ui->lineEdit_modif_type_rev->text());
       q.bindValue(":PRIX_FACTURE",ui->lineEdit_modif_facture_rev->text());
       q.bindValue(":PRIX_ACHAT",ui->lineEdit_modif_achat_rev->text());
      //  rev.calculer_encaissement();
       q.bindValue(":ENCAISSEMENT",res5);



       if(q.exec())
       {
           ui->tableView_affich_rev->setModel(rev.afficher_revenu());//refresh
            ui-> tableView_modif_rev ->setModel(rev.afficher_revenu());//refrech modif

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


void menuadmin::on_pushButton_supp_rev_clicked()
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

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un revenu"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}
/*ui->tableView_affich_sal->setModel(sal.afficher_salaire());//refresh
        ui->tableView_modif_sal ->setModel(sal.tri_affiche());//refrech modif
lineEdit_cherch_perso*/



void menuadmin::on_tableView_modif_sal_activated(const QModelIndex &index)
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
             ui->lineEdit_montant_sal_2->setText(query.value(3).toString());
             ui->lineEdit_modif_perso->setText(query.value(6).toString());
             ui->lineEdit_cherch_perso->setText(query.value(6).toString());

         }
     }
         else  {QMessageBox::warning(this,"salaire","erreur");}
}


void menuadmin::on_pushButton_modif_sal_clicked()
{
     QString val=ui->lineEdit_cherch_perso_2->text();
    QSqlQuery q;
       sal.ajouter_sanction();
       sal.ajouter_promotion();


       q.prepare("update SALAIRE set  DATE_VERSEMENT=:DATE_VERSEMENT,DATE_MODIF=:DATE_MODIF,MONTANT_SALAIRE=:MONTANT_SALAIRE,SANCTION=:SANCTION,PROMOTION=:PROMOTION,NOM_PERSONNEL=:NOM_PERSONNEL where ID_SALAIRE='"+val+"'" );
       q.bindValue(":DATE_VERSEMENT",ui->dateEdit_modif_vers->dateTime());
       q.bindValue(":DATE_MODIF",ui->dateEdit_modif_modif->dateTime());
       q.bindValue(":MONTANT_SALAIRE",ui->lineEdit_montant_sal_2->text());
       q.bindValue(":SANCTION",ui->lineEdit_modif_sanc->text());
       q.bindValue(":PROMOTION",ui->lineEdit_modif_promo->text());
         q.bindValue(":NOM_PERSONNEL",ui->lineEdit_cherch_perso->text());


       //MONTANT_SALAIRE=:montant_salaire,
       if(q.exec())
       {
           ui->tableView_affich_sal->setModel(sal.afficher_salaire());//refresh
           ui->tableView_modif_sal ->setModel(sal.tri_affiche());//refrech modif
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

void menuadmin::on_pushButton_supp_sal_clicked()
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

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un salaire"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}
