#ifndef START_H
#define START_H
#include "reservation.h"
#include <QDialog>
#include"billet.h"
namespace Ui {
class start;
}

class start : public QDialog
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = nullptr);
    ~start();
private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_mise_a_jour_clicked();

    void on_afficher_clicked();

    void on_tabreservation_2_activated(const QModelIndex &index);

    void on_checkBox_guide_toggled(bool checked);

    void on_checkBox_billet_toggled(bool checked);


    void on_checkBox_3_toggled(bool checked);

private:
    Ui::start *ui;

    reservation tmpreservation;
    billet tmpbillet ;
};

#endif // START_H
