#include "mainmenu.hh"
#include "ui_mainmenu.h"


mainmenu::mainmenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainmenu),
    mainWin_(new MainWindow),
    controlsWin_(new controls),
    scoresWin_(new highscores)
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
    delete mainWin_;
    delete controlsWin_;
    delete scoresWin_;
}

void mainmenu::newGame()
{
    mainWin_->startTimers();
    mainWin_->show();
    this->close();
}

void mainmenu::openControls()
{
    controlsWin_->exec();
}

void mainmenu::openScores()
{
    scoresWin_->show();
}

