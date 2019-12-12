#ifndef MENU_AGENT_H
#define MENU_AGENT_H

#include <QDialog>
#include "reservation.h"
#include <QDialog>
#include"billet.h"
#include "client.h"
#include "reservation.h"
#include "transport.h"
#include "arduino.h"


namespace Ui {
class menu_agent;
}

class menu_agent : public QDialog
{
    Q_OBJECT

public:
    explicit menu_agent(QWidget *parent = nullptr);
    ~menu_agent();
    void shootscreen();
    void update_label();

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

    void on_checkBox_billet_stateChanged(int arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_client_widget_currentChanged(int index);

    void on_pushButton_7_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_18_clicked();

private:
    Ui::menu_agent *ui;
    reservation tmpreservation;
        billet tmpbillet ;
        client c;
          Transport T;
           client cl;
           arduino A;
            QByteArray data;

};

#endif // MENU_AGENT_H
