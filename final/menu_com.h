#ifndef MENU_COM_H
#define MENU_COM_H

#include <QDialog>

namespace Ui {
class menu_com;
}

class menu_com : public QDialog
{
    Q_OBJECT

public:
    explicit menu_com(QWidget *parent = nullptr);
    ~menu_com();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_fb_clicked();

    void on_pushButton_insta_clicked();

    void on_pushButton_lkn_clicked();

private:
    Ui::menu_com *ui;
};

#endif // MENU_COM_H
