#include "mainwindow.h"
#include "menuadmin.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString id =ui-> lineEdit_id->text();

    QString mdp=ui-> lineEdit_mdp->text();

    if ((id == "admin" &&  mdp == "admin")||(id =="agent" && mdp == "agent") ||(id =="respcom" && mdp == "respcom")||(id =="1" && mdp == "1") )
    {
         ui->label_connecting->setText("id et mot de passe correct");
         this->hide();
        menuadmin menu;
       menu.setModal(true);

        menu.exec();

    }

else {
        ui->label_connecting->setText("id ou mot de passe incorrect");
}
}
