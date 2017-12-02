#ifndef ENCOUNTER_HH
#define ENCOUNTER_HH

#include <QDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QWidget>
#include "starsystem.hh"
#include "statistics.hh"



namespace Ui {
class encounter;
}

class encounter : public QDialog
{
    Q_OBJECT

public:
    explicit encounter(QWidget *parent = 0);
    ~encounter();
    void setStarSystem(std::shared_ptr<Common::StarSystem> givenStarSystem);
    void rejection();
    void setCorrectAnswer();
    void infoDialog();
    void firstRightDialog(); //ensimmäisen oikean valinnan jälkeen
    void successfulEncounter();

    void setStatistics(Student::Statistics &stats);
    enum OUTCOME {
        SavedNormal,
        SavedWealthy,
        SavedBribe,
        Lost
    };
private:
    Ui::encounter *ui;
    encounter::OUTCOME outcome_;
<<<<<<< HEAD
    std::shared_ptr<Common::StarSystem> currentStarSystem_;
    std::string returnableOutcome_;
=======
    Common::StarSystem::ECONOMY_TYPE currentStarSystemEconomy_;
>>>>>>> 7e24bd36cb3cabc8d7c2f3bad7391cf40376386d
};

#endif // ENCOUNTER_HH
