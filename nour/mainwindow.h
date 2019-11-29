#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "depenses.h"
#include "salaire.h"
#include "revenu.h"
#include <QSqlQueryModel>




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
 //  QString on_checkBox_salaire_clicked();
// QString on_checkBox_achat_clicked();
   // QString get_dep_type_depence(){return dep.get_type_depenses();}
    void on_pushButton_ajout_depense_clicked();

    void on_pushButton_supprimer_depense_clicked();



    //void on_pushButton_3_clicked();


    void on_pushButton_clicked();

    void on_pushButton_ajout_salaire_clicked();


    void on_pushButton_supp_salaire_clicked();



    void on_pushButton_ajouter_revenu_clicked();

    void on_pushButton_supp_revenu_clicked();

    void on_pushButton_modif_sal_clicked();

    void on_pushButton_modif_dep_clicked();


    void on_pushButton_modif_revenu_clicked();

    void on_pushButton_trier_clicked();



    void on_lineEdit_cherch_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Depenses dep;
    salaire sal;
    Revenu rev;


};
#endif // MAINWINDOW_H
