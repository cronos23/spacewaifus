#include "highscores.hh"
#include "ui_highscores.h"

highscores::highscores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::highscores)
{
    ui->setupUi(this);
}

highscores::~highscores()
{
    delete ui;
}

//void highscores::readScores()
//{
//    ifstream file;
//    file.open("leaderboard.txt");

//}
