#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QtDebug>
#include <QtMultimedia/QMediaPlayer>

int main(int argc, char *argv[])
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/NOUR/Desktop/Rockabye - Clean Bandit (Oud cover) by Ahmed Alshaiba.mp3"));
    player->setVolume(50);
    player->play();
    QApplication a(argc, argv);
    CONNECTION c;

    bool test=c.ouvrirCONNECTION();
    MainWindow w;
    if(test)
    {w.show();

        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

      return a.exec();

}


