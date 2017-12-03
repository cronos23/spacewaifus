#ifndef ENCOUNTER_HH
#define ENCOUNTER_HH

#include <QDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QWidget>
#include "mainwindowutility.hh"
#include "starsystem.hh"
#include "statistics.hh"

/**
 * @file
 * @brief Encounter with waifu/spaceship.
 */

namespace Ui {

/**
 * @brief Encounter triggers when the player flies into a star system that houses at least one waifu (cargo ship).
 *
 * When triggered, encounter opens as an exec and stops all of mainWindows timers. This means that while
 * an encounter is open, no other part of the game is being updated.
 *
 * When an encounter starts, the player is presented with a conversation dialog with different options.
 * The first set of responses are the same for every encounter. If the right option is chosen, the player is
 * presented with more options, which are determined by the star systems waifu type.
 *
 * After the player chooses a dialog option from the second set of options, they are presented with feedback on
 * the success of their seduction attempts. When the player chooses to leave by pressing the only active button
 * in the last screen, the encounter closes and lets mainWindow continue operation.
 */

class encounter;
}

class encounter : public QDialog
{
    Q_OBJECT

public:
    explicit encounter(QWidget *parent = 0);
    ~encounter();
    /**
     * @brief Sets the correct waifu_type_ private attribute for the current encounter.
     * @param The waifu type is determined by accessing the ECONOMY_TYPE of the given star system.
     */
    void setWaifuType(std::shared_ptr<Common::StarSystem> givenStarSystem);
    /**
     * @brief
     * @param stats
     */

    void updateStatistics(Student::Statistics &stats);
    enum OUTCOME {
        SavedNormal,
        SavedWealthy,
        SavedBribe,
        Lost
    };
private slots:
    void rejection();
    void infoDialog();
    void firstRightDialog(); //ensimmäisen oikean valinnan jälkeen
    void successfulEncounter();

private:
    void setCorrectAnswer();
    Ui::encounter *ui;
    encounter::OUTCOME outcome_;
    std::string waifuType_;

};

#endif // ENCOUNTER_HH
