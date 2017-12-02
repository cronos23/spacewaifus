#include "mainmenu.hh"
#include "ui_mainmenu.h"


mainmenu::mainmenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainmenu),
    mainWin(new MainWindow),
    controlsWin(new controls)
{
    ui->setupUi(this);

    QObject::connect(ui->play_button, &QPushButton::clicked,
            this, &mainmenu::newGame);

    QObject::connect(ui->controls_button, &QPushButton::clicked,
             this, &mainmenu::openControls);
}

mainmenu::~mainmenu()
{
    delete ui;
    delete mainWin;
    delete controlsWin;
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

