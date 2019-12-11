#include "menu_agent.h"
#include "ui_menu_agent.h"

menu_agent::menu_agent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu_agent)
{
    ui->setupUi(this);
}

menu_agent::~menu_agent()
{
    delete ui;
}
