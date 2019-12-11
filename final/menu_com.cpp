#include "menu_com.h"
#include "ui_menu_com.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QPixmap>
#include <QDesktopServices>

menu_com::menu_com(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu_com)
{
    ui->setupUi(this);
}

menu_com::~menu_com()
{
    delete ui;
}

void menu_com::on_pushButton_clicked()
{
    QString link="https://mail.google.com/mail/u/0/#inbox";
    QDesktopServices::openUrl(QUrl(link));
}

void menu_com::on_pushButton_fb_clicked()
{
    QString link="https://www.facebook.com/";
    QDesktopServices::openUrl(QUrl(link));
}

void menu_com::on_pushButton_insta_clicked()
{
    QString link="https://www.instagram.com/";
   QDesktopServices::openUrl(QUrl(link));
}

void menu_com::on_pushButton_lkn_clicked()
{
    QString link="https://www.linkedin.com/";
   QDesktopServices::openUrl(QUrl(link));
}
