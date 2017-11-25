#ifndef MAINMENU_HH
#define MAINMENU_HH

#include <QWidget>
#include "mainwindow.hh"
#include "controls.hh"

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
    void openControls();

private:
    Ui::mainmenu *ui;
    MainWindow *mainWin;
    controls *controlsWin;

};

#endif // MAINMENU_HH
