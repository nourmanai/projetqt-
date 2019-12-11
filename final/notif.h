#ifndef NOTIF_H
#define NOTIF_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPropertyAnimation>
#include <QTimer>
#include <QPainter>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

class notif
        //:public QWidget
{
   /* Q_OBJECT
   Q_PROPERTY(float popupOpacity READ getPopupOpacity WRITE setPopupOpacity)

   void setPopupOpacity(float opacity);
   float getPopupOpacity() const;
public:
    notif();
    explicit  notif(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *event);
public slots:
    void setPopupText(const QString& text);
    void show();

private slots:
    void hideAnimation();
    void hide();

private:
    QLabel label;
    QGridLayout layout;
    QPropertyAnimation animation;
    float popupOpacity;
    QTimer *timer;*/
private:
    int num;
public:
    notif();
    void notification_sup_produit(QString );
    void notification_Ouverture(QString id);
    void notification_sup_produitp(QString id);



};

#endif // NOTIF_H
