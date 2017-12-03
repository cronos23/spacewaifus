#ifndef MAINMENU_HH
#define MAINMENU_HH

#include <QDialog>
#include "mainwindow.hh"
#include "controls.hh"
#include "highscores.hh"

namespace Ui {
class mainmenu;
}

class mainmenu : public QDialog
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = 0);
    ~mainmenu();

public slots:
    void newGame();
    void openControls();
    void openScores();

private:
    Ui::mainmenu *ui;
    MainWindow *mainWin;
    controls *controlsWin;
    highscores *scoresWin;

};

#endif // MAINMENU_HH
