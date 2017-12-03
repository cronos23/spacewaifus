#ifndef ENCOUNTER_HH
#define ENCOUNTER_HH

#include <QDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QWidget>
#include "mainwindowutility.hh"
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

    void setStatistics(Student::Statistics &stats);
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
