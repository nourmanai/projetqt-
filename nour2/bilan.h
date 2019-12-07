#ifndef BILAN_H
#define BILAN_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QSqlQueryModel>

class Bilan
{
private:
     int id_depense;
    int id_revenu;
    QString type_bilan ;
public:
    Bilan();
    Bilan( int,int,QString);
};

#endif // BILAN_H
