#include "bilan.h"
#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <QSqlError>
#include "menuadmin.h"

Bilan::Bilan()
{
     id_depense=111;
    id_revenu=222;
   type_bilan="annuel" ;
}
Bilan::Bilan(int  id_depense,int id_revenu,QString type_bilan)
{
     this->id_depense= id_depense;
    this->id_revenu=id_revenu;
   this->type_bilan=type_bilan ;
}
