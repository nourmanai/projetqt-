#ifndef MAIL_H
#define MAIL_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPropertyAnimation>
#include <QTimer>
#include <QPainter>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

class mail :public QWidget
{

    Q_OBJECT


       Q_PROPERTY(float popupOpacity READ getPopupOpacity WRITE setPopupOpacity)

       void setPopupOpacity(float opacity);
       float getPopupOpacity() const;

public:
    mail();
    void notification_sup_produit(QString );
    void notification_Ouverture(QString id);
    void notification_sup_produitp(QString id);



private:
    int num;



};

#endif // MAIL_H
