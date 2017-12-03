#include "game_over.hh"
#include "ui_game_over.h"

game_over::game_over(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game_over),
    scores_(new highscores)
{
    ui->setupUi(this);
}

game_over::~game_over()
{
    delete ui;
}

void game_over::setPoints(unsigned int points)
{
    points_ = points;
    if (scores_->compareScoreToVector(points_)) {
        QObject::connect(ui->save_button, &QPushButton::clicked, this, &game_over::exit_and_save);
        ui->save_button->setEnabled(true);
        ui->top10_label->setText("You're in the top 10! Congrats!");
    }
    else {
        ui->save_button->setEnabled(false);
        ui->name_label->setText("");
        ui->top10_label->setText("Unfortunately you didn't reach the leaderboard. "
                                 "\nBetter luck next time!");
    }
    std::ostringstream final_points;
    final_points << "Your points : " << points_;
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
    final_rejections << "You got rejected by " << rejections << " spaceships";
    std::string final_rejectionsString = final_rejections.str();
    ui->rejected_label->setText(QString::fromStdString(final_rejectionsString));
}

void game_over::exit_and_save() {
    std::string name = ui->name_edit->text().toStdString();
    for (int i = name.size(); i < 3; i++) {
        name.append("A");
    }
    scores_->setNameandScore(name, points_);
    scores_->writeToFile();
    this->close();
}
