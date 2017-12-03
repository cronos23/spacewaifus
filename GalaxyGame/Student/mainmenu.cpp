#include "mainmenu.hh"
#include "ui_mainmenu.h"


mainmenu::mainmenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainmenu),
    mainWin(new MainWindow),
    controlsWin(new controls),
    scoresWin(new highscores)
{
    ui->setupUi(this);

    QObject::connect(ui->play_button, &QPushButton::clicked,
            this, &mainmenu::newGame);

    QObject::connect(ui->controls_button, &QPushButton::clicked,
             this, &mainmenu::openControls);

    QObject::connect(ui->highscore_button, &QPushButton::clicked,
                     this, &mainmenu::openScores);
}

mainmenu::~mainmenu()
{
    delete ui;
    delete mainWin;
    delete controlsWin;
    delete scoresWin;
}

void mainmenu::newGame()
{
    mainWin->startTimers();
    mainWin->show();
    this->close();
}

void mainmenu::openControls()
{
    controlsWin->exec();
}

void mainmenu::openScores()
{
    scoresWin->show();
}

