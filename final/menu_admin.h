#ifndef MENU_ADMIN_H
#define MENU_ADMIN_H

#include <QDialog>
#include "depenses.h"
#include "salaire.h"
#include "revenu.h"
#include "arduino.h"

namespace Ui {
class menu_admin;
}

class menu_admin : public QDialog
{
    Q_OBJECT

public:
    explicit menu_admin(QWidget *parent = nullptr);
    ~menu_admin();

private slots:
    void on_pushButton_ajou_dep_clicked();

    void on_pushButton_tri_dep_clicked();

    void on_pushButton_modif_dep_clicked();

    void on_pushButton_ajout_rev_clicked();

    void on_pushButton_ajout_sal_clicked();

    void on_pushButton_tri_rev_clicked();

    void on_pushButton_tri_sal_clicked();

    void on_lineEdit_cherch_perso_textChanged(const QString &arg1);

    void on_lineEdit_supp_rev_textChanged(const QString &arg1);

    void on_lineEdit_supp_dep_textChanged(const QString &arg1);

    void on_tableView_modif_dep_activated(const QModelIndex &index);

    void on_pushButton_supp_dep_clicked();

    void on_tableView_modif_rev_activated(const QModelIndex &index);

    void on_pushButton_modif_rev_clicked();

    void on_pushButton_supp_rev_clicked();

    void on_tableView_modif_sal_activated(const QModelIndex &index);

    void on_pushButton_modif_sal_clicked();

    void on_pushButton_supp_sal_clicked();

    void on_pushButton_mail_clicked();

    void on_pushButton_fb2_clicked();

    void on_pushButton_insta2_clicked();

    void on_pushButton_lkn2_clicked();

private:
    Ui::menu_admin *ui;
    Depenses dep;
    Revenu rev;
    Salaire sal;
    QByteArray data; // variable contenant les données reçues

    arduino A; // objet temporaire

};

#endif // MENU_ADMIN_H
