#ifndef GAME_OVER_HH
#define GAME_OVER_HH

#include <QMessageBox>
#include <QWidget>
#include <sstream>
#include "highscores.hh"

namespace Ui {
class game_over;
}

/**
 * @brief QWidget that's shown when the game ends, either by the player clicking
 * Quit Game or by gameTimer_ sending a timeOut -signal. Shows relevant information
 * about the finished game to the player.
 */
class game_over : public QWidget
{
    Q_OBJECT

public:
    explicit game_over(QWidget *parent = 0);
    ~game_over();
    /**
     * @brief Used to set points_label to display the correct points.
     * @param When the function is called, it's parameter should come from a statistics
     * object.
     */
    void setPoints(unsigned int points);
    /**
     * @brief Used to set dated_label to display the correct points.
     * @param When the function is called, it's parameter should come from a statistics
     * object.
     */
    void setDatedShips(unsigned int datedShips);
    /**
     * @brief Used to set rejected_label to display the correct points.
     * @param When the function is called, it's parameter should come from a statistics
     * object.
     */
    void setRejections(unsigned int rejections);

private slots:
    void exit_and_save();
private:
    Ui::game_over *ui;
    highscores * scores_;
    unsigned int points_;
};

#endif // GAME_OVER_HH
