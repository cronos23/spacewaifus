#ifndef ENCOUNTER_HH
#define ENCOUNTER_HH

#include <QDialog>
#include <QWidget>
#include "starsystem.hh"
#include <QPixmap>
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
    std::shared_ptr<Common::StarSystem> currentStarSystem_;
    std::string returnableOutcome_;
};

#endif // ENCOUNTER_HH
