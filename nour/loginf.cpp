#include "loginf.h"
#include "ui_loginf.h"

loginf::loginf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginf)
{
    ui->setupUi(this);
}

loginf::~loginf()
{
    delete ui;
}

void loginf::on_pushButton_login_clicked()
{
    QString id =ui-> lineEdit_id->text();

    QString mdp=ui-> lineEdit_mdp->text();

    if ((id == "admin" &&  mdp == "admin")||(id =="agent" && mdp == "agent") ||(id =="respcom" && mdp == "respcom") )
    {
         ui->label_statut->setText("id et mot de passe correct");
         this->hide();
         MainWindow w;
        w.show();


    }

else {
        ui->label_statut->setText("id et mot de passe incorrect");
}
}
