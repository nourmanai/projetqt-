#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include"transport.h"
#include <QMainWindow>
#include<QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_refresh_clicked();


     void on_table_afficher_activated(const QModelIndex &index);

     void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    client c;
    Transport T;
    client cl;
};
#endif // MAINWINDOW_H
