#include "mail.h"
#include <QSystemTrayIcon>

mail::mail()
{
num=0;
}
void mail::notification_sup_produit(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   notifyIcon->setIcon(QIcon("C:/Users/NOUR/Desktop/notif/notif"));
   QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","Un produit a ete supprimer de la base !",QSystemTrayIcon::Information,15000);
//num++;
}

void mail::notification_sup_produitp(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/NOUR/Desktop/notif/notif"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","Un produit P a ete supprimer de la base !",QSystemTrayIcon::Information,15000);
//num++;
}


void mail ::notification_Ouverture(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/NOUR/Desktop/notif/notif"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("Gestion de produit ","Nouvelle instance ouverte",QSystemTrayIcon::Information,15000);
//num++;
}
