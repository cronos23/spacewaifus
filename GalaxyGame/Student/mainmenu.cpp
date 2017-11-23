#include "mainmenu.hh"
#include "mainwindow.hh"
#include "ui_mainmenu.h"

mainmenu::mainmenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainmenu)
{
    ui->setupUi(this);

    connect(ui->play_button, SIGNAL(triggered(bool)),
            this, SLOT(newGame()));
}

mainmenu::~mainmenu()
{
    delete ui;
}

void mainmenu::newGame()
{
    MainWindow mainWin;
    mainWin.show();
    this->close();
}
