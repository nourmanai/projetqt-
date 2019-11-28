#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "start.h"
#include<QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix5("C:/Users/admin/Desktop/bg.png");
    ui->label_bg->setPixmap(pix5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    start start ;
    start.setModal(true) ;
    start.exec() ;


}
