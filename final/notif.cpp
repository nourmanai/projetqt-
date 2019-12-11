#include "notif.h"
#include <QSystemTrayIcon>
#include <QSystemTrayIcon>
#include<QString>

notif::notif()
{
num=0;
}

void notif::notification_sup_produit(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   notifyIcon->setIcon(QIcon("C:/Users/NOUR/Desktop/notif/notif"));
   QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","Une instance a ete supprimer de la base !",QSystemTrayIcon::Information,15000);
//num++;
}

void notif::notification_sup_produitp(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/NOUR/Desktop/notif/notif"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","Une instance P a ete supprimer de la base !",QSystemTrayIcon::Information,15000);
//num++;
}


void notif::notification_Ouverture(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/NOUR/Desktop/notif/notif"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("Gestion de comptabilite ","Nouvelle instance ouverte",QSystemTrayIcon::Information,15000);
//num++;
}
