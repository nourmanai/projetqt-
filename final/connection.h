#ifndef CONNECTION_H
#define CONNECTION_H

#include<QSqlDatabase>

class CONNECTION
{
private:
     QSqlDatabase db;

public:
    CONNECTION();
    bool ouvrirCONNECTION();
    void fermerCONNECTION();

};

#endif // CONNECTION_H

