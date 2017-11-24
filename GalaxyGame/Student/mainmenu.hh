#ifndef MAINMENU_HH
#define MAINMENU_HH

#include <QWidget>
#include "mainwindow.hh"

namespace Ui {
class mainmenu;
}

class mainmenu : public QWidget
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = 0);
    ~mainmenu();

public slots:
    void newGame();

private:
    Ui::mainmenu *ui;
    MainWindow *mainWin;

};

#endif // MAINMENU_HH
