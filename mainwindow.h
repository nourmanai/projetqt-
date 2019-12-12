#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"arduino.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

 //   void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

   // void on_pushButton_4_clicked();

  //  void on_pushButton_4_windowTitleChanged(const QString &title);

//    void on_pushButton_16_clicked();

   // void on_pushButton_15_clicked();

   // void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

   // void on_lineEdit_textChanged(const QString &cin1);

 //   void on_cin1_textChanged(const QString &arg1);

  //  void on_cin1_cursorPositionChanged(int arg1, int arg2);
   //void update_label();
   //void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

   void on_pushButton_supprimer_clicked();

   void on_pushButton_modifier_clicked();

   //void on_recherche_textChanged(const QString &arg1);

   void on_chercher_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QByteArray data; // eli bech tekhdou mel arduino
    Arduino A;//objet
};
#endif // MAINWINDOW_H
