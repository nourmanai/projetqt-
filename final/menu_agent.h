#ifndef MENU_AGENT_H
#define MENU_AGENT_H

#include <QDialog>
#include "reservation.h"
#include <QDialog>
#include"billet.h"
#include "client.h"
#include "reservation.h"
#include "transport.h"


namespace Ui {
class menu_agent;
}

class menu_agent : public QDialog
{
    Q_OBJECT

public:
    explicit menu_agent(QWidget *parent = nullptr);
    ~menu_agent();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_mise_a_jour_clicked();

    void on_afficher_clicked();

    void on_checkBox_guide_toggled(bool checked);

    void on_checkBox_3_toggled(bool checked);

    void on_checkBox_billet_toggled(bool checked);

    void on_rechercher_clicked();

    void on_trier_clicked();

    void on_pushButton_2_clicked();

    void on_refresh_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_table_afficher_activated(const QModelIndex &index);

private:
    Ui::menu_agent *ui;
    reservation tmpreservation;
        billet tmpbillet ;
        client c;
          Transport T;
           client cl;

};

#endif // MENU_AGENT_H
