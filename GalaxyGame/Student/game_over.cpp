#include "game_over.hh"
#include "ui_game_over.h"

game_over::game_over(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game_over)
{
    ui->setupUi(this);
}

game_over::~game_over()
{
    delete ui;
}

void game_over::setPoints(unsigned int points)
{
    std::ostringstream final_points;
    final_points << "Your points : " << points;
    std::string final_pointsString = final_points.str();
    ui->points_label->setText(QString::fromStdString(final_pointsString));
}

void game_over::setDatedShips(unsigned int datedShips)
{
    std::ostringstream final_datedShips;
    final_datedShips << "You dated " << datedShips << " spaceships.";
    std::string final_datedShipsString = final_datedShips.str();
    ui->dated_label->setText(QString::fromStdString(final_datedShipsString));
}

void game_over::setRejections(unsigned int rejections)
{
    std::ostringstream final_rejections;
    final_rejections << "Your got rejected by " << rejections << " spaceships";
    std::string final_rejectionsString = final_rejections.str();
    ui->rejected_label->setText(QString::fromStdString(final_rejectionsString));
}
