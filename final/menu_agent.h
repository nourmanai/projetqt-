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
#include "conge.h"
#include"mainwindow.h"

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
    void shootscreen1();
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

    void on_pushButton_perso1_2_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_modifier_3_clicked();

    void on_chercher_2_textChanged(const QString &arg1);

    void on_Ajouter_conge_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_supprimer_3_clicked();

    void on_pushButton_23_clicked();

    void on_screen_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_idContratsRechercher_textChanged(const QString &arg1);

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_26_clicked();

    void on_lineEdit_28_textChanged(const QString &arg1);

    void on_pushButton_27_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::menu_agent *ui;
    reservation tmpreservation;
        billet tmpbillet ;
        client c;
          Transport T;
           client cl;
           arduino A;
            QByteArray data;
            conge C;
MainWindow M ;
};

#endif // MENU_AGENT_H
