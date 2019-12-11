#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menu_admin.h"
#include "menu_agent.h"
#include "menu_com.h"
#include "arduino.h"
#include <QSqlQuery>
#include <QPixmap>
#include <QDesktopServices>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
     // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::updatelabel()
{
    data=A.read_from_arduino();
}


void MainWindow::on_pushButton_login_clicked()
{
    QString id =ui-> lineEdit_id->text();

    QString mdp=ui-> lineEdit_mdp->text();

    if ((id == "admin" &&  mdp == "admin")||(id =="agent" && mdp == "agent") ||(id =="respcom" && mdp == "respcom")||(id =="1" && mdp == "1") )
    {
         ui->label_connecting->setText("id et mot de passe correct");
         if ((id == "admin" &&  mdp == "admin")||(id =="1" && mdp == "1"))
         {
             this->hide();
            menu_admin menu;
           menu.setModal(true);

            menu.exec();
         }
         if((id =="agent" && mdp == "agent")||(id =="1" && mdp == "1"))
         {
             this->hide();
            menu_agent menu;
           menu.setModal(true);

            menu.exec();
         }
         if((id =="respcom" && mdp == "respcom")||(id =="1" && mdp == "1"))
        {
         this->hide();
        menu_com menu;
       menu.setModal(true);

        menu.exec();
         }

    }

else {
        ui->label_connecting->setText("id ou mot de passe incorrect");
}
}

