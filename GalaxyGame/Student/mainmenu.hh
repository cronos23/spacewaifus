#ifndef MAINMENU_HH
#define MAINMENU_HH

#include <QDialog>
#include "mainwindow.hh"
#include "controls.hh"
#include "highscores.hh"

namespace Ui {
class mainmenu;
}
/**
 * @brief Mainmenu is the first view presented to the user after running the application.
 * It consists of buttons that launch different QWidgets.
 */
class mainmenu : public QDialog
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = 0);
    ~mainmenu();

private slots:
    /**
     * @brief Launches a MainWindow that runs the game in a graphicsview. Closes the mainmenu.
     */
    void newGame();
    /**
     * @brief Launches a controls QDialog that shows tips and controls that help the player get
     * into the game.
     */
    void openControls();
    /**
     * @brief Opens a QWidget that gets saved high scores from a text file and shows them to the user.
     * Also catches exceptions thrown by highscores in case of a missing of incorrect file.
     */
    void openScores();

private:
    Ui::mainmenu *ui;
    MainWindow *mainWin_;
    controls *controlsWin_;
    highscores *scoresWin_;

};

#endif // MAINMENU_HH
