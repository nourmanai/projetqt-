#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_4_windowTitleChanged(const QString &title);

    void on_pushButton_16_clicked();

    void on_pushButton_15_clicked();

   // void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_lineEdit_textChanged(const QString &cin1);

    void on_cin1_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
