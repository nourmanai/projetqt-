#ifndef MENUADMIN_H
#define MENUADMIN_H

#include <QDialog>
#include "bilan.h"
#include "depenses.h"
#include "revenu.h"
#include "salaire.h"
#include "arduino.h"


namespace Ui {
class menuadmin;
}

class menuadmin : public QDialog
{
    Q_OBJECT

public:
    explicit menuadmin(QWidget *parent = nullptr);
    ~menuadmin();

private slots:
    void on_pushButton_ajout_dep_clicked();

    void on_pushButton_ajout_rev_clicked();

    void on_pushButton_ajout_sal_clicked();

    void on_pushButton_tri_dep_clicked();

    void on_pushButton_tri_rev_clicked();

    void on_pushButton_tri_sal_clicked();

    void on_lineEdit_cherch_perso_textChanged(const QString &arg1);

    void on_lineEdit_supp_rev_textChanged(const QString &arg1);

    void on_lineEdit_supp_dep_textChanged(const QString &arg1);

    void on_tableView_modif_dep_activated(const QModelIndex &index);

    void on_pushButton_modif_dep_clicked();

    void on_pushButton_supp_dep_clicked();

    void on_tableView_modif_rev_activated(const QModelIndex &index);

    void on_pushButton_modif_rev_clicked();

    void on_pushButton_supp_rev_clicked();

    void on_tableView_modif_sal_activated(const QModelIndex &index);

    void on_pushButton_modif_sal_clicked();

    void on_pushButton_supp_sal_clicked();

    void on_envoyer_clicked();

    void on_retour_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::menuadmin *ui;
    Depenses dep;
    Revenu rev;
    Salaire sal;
    QByteArray data; // variable contenant les données reçues

    arduino A; // objet temporaire

};

#endif // MENUADMIN_H
