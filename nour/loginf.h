#ifndef LOGINF_H
#define LOGINF_H

#include <QDialog>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include "mainwindow.h"



namespace Ui {
class loginf;
}

class loginf : public QDialog
{
    Q_OBJECT

public:
    explicit loginf(QWidget *parent = nullptr);
    ~loginf();

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::loginf *ui;
};

#endif // LOGINF_H
