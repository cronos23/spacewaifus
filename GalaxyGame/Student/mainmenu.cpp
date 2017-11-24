#include "mainmenu.hh"
#include "ui_mainmenu.h"


mainmenu::mainmenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainmenu),
    mainWin(new MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->play_button, &QPushButton::clicked,
            this, &mainmenu::newGame);
}

mainmenu::~mainmenu()
{
    delete ui;
    delete mainWin;
}

void mainmenu::newGame()
{
    mainWin->show();
    this->close();
}
