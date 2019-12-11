#ifndef MENU_AGENT_H
#define MENU_AGENT_H

#include <QDialog>

namespace Ui {
class menu_agent;
}

class menu_agent : public QDialog
{
    Q_OBJECT

public:
    explicit menu_agent(QWidget *parent = nullptr);
    ~menu_agent();

private:
    Ui::menu_agent *ui;
};

#endif // MENU_AGENT_H
