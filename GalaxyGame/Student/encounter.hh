#ifndef ENCOUNTER_HH
#define ENCOUNTER_HH

#include <QWidget>
#include "starsystem.hh"
#include <QPixmap>



namespace Ui {
class encounter;
}

class encounter : public QWidget
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

private:
    Ui::encounter *ui;
    std::shared_ptr<Common::StarSystem> currentStarSystem_;
};

#endif // ENCOUNTER_HH
