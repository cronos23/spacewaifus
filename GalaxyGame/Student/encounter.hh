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
     * @post Exception guarantee: nothrow
     */
    void setWaifuType(std::shared_ptr<Common::StarSystem> givenStarSystem);
    /**
     * @brief Updates statistics according to the outcome of the encounter.
     * @param A reference to the statistics object created in mainWindow is given to the function for updating.
     * @pre outcome_ must be set to a value.
     * @post Exception guarantee: nothrow
     */
    void updateStatistics(Student::Statistics &stats);
    /**
     * @brief The OUTCOME enum has values for all different possible outcomes of the encounter dialog.
     */
    enum OUTCOME {
        SavedNormal,
        SavedWealthy,
        SavedBribe,
        Lost
    };
private slots:
    /**
     * @brief Rejection is called when an incorrect option is chosen by the player. It sets the outcome_ to Lost
     * and ends the encounter when the player chooses to leave.
     * @pre Encounter has to have a waifu_type_ set by setWaifuType
     * @post Exception guarantee: nothrow
     */
    void rejection();
    /**
     * @brief Called when info_button is clicked in the first dialog. Shows the player info, which is selected
     * according to the encounters waifu_type_.
     * @pre Encounter has to have a waifu_type_ set by setWaifuType
     * @post Exception guarantee: nothrow
     */
    void infoDialog();
    /**
     * @brief Called if the player chooses correctly in the first dialog. Sets the new dialog options according
     * to waifu_type_
     * @pre Encounter has to have a waifu_type_ set by setWaifuType
     * @post Exception guarantee: nothrow
     */
    void firstRightDialog();
    /**
     * @brief Called if the player chooses correctly after firstRightDialog is called. Sets outcome_ to either
     * SavedNormal, SavedWealthy or SavedBribe according to waifu_type_.
     * @pre Encounter has to have a waifu_type_ set by setWaifuType
     * @post Exception guarantee: nothrow
     */
    void successfulEncounter();

private:
    /**
     * @brief Called in setWaifuType. Connects one of the dialog buttons to succesfulEncounter according to
     * waifu_type_.
     * @pre Encounter has to have a waifu_type_ set by setWaifuType
     * @post Exception guarantee: nothrow
     */
    void setCorrectAnswer();
    Ui::encounter *ui;
    /**
     * @brief Stores the outcome of the encounter so statistics can be updated correctly in updateStatistics.
     */
    encounter::OUTCOME outcome_;
    /**
     * @brief Stores the waifu type set by setWaifuType. Used for updating statistics in updateStatistics.
     */
    std::string waifuType_;

};

#endif // ENCOUNTER_HH
