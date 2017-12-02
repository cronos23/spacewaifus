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
    std::string returnOutcome();

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
    Common::StarSystem::ECONOMY_TYPE currentStarSystemEconomy_;
=======
    std::shared_ptr<Common::StarSystem> currentStarSystem_;
    std::string outcome_;
>>>>>>> f5b3cdea80332b98a9928e53e91a3fab6b033706
};

#endif // ENCOUNTER_HH
