#include "highscores.hh"
#include "ui_highscores.h"

highscores::highscores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::highscores)
{
    ui->setupUi(this);
    try {
        top10_ = readFile();
    } catch (Common::IoException e) {
        std::cout << e.msg() << std::endl <<
                     "The program will now exit." << std::endl;
        exit(1);
    }

    std::sort(top10_.begin(), top10_.end(), highscores::less_than_score);

    for (auto vectorStruct:top10_) {
        std::ostringstream name_and_score;
        name_and_score << vectorStruct.name << " : " << vectorStruct.score << "\n";
        std::string name_and_score_string = name_and_score.str();
        ui->listWidget->addItem(QString::fromStdString(name_and_score_string));
    }
}

highscores::~highscores()
{
    delete ui;
}

std::vector<struct highscores::playerScore> highscores::readFile() {
    std::vector<playerScore> scoreVector;
    std::string currentrow;
    std::ifstream scoreBoard("leaderboard.txt");
    if (!scoreBoard) {
        throw Common::IoException("leaderboard.txt missing");
    }
    int row_counter = 10;
    while (std::getline(scoreBoard, currentrow)) {
        try {
        std::string name = currentrow.substr(0,3);
        int score = std::stoi(currentrow.substr(3));
        highscores::playerScore rowstruct;
        rowstruct.name = name;
        rowstruct.score = score;
        scoreVector.push_back(rowstruct);
        --row_counter;
        }
        catch (std::out_of_range e) {
            std::cout << "leaderboard.txt not properly formatted." << std::endl
                      << "The program will now exit" << std::endl;
            exit(1);
        }
    }
    if (row_counter != 0) {
        throw Common::IoException("Wrong amount of rows in file");
    }
    return scoreVector;
}

bool highscores::compareScoreToVector(unsigned int score){

    for (auto vectorStruct:top10_) {
        if (score > vectorStruct.score) {
            return true;
        }
    }
    return false;
}

void highscores::setNameandScore(std::string name, unsigned int score)
{
    name_ = name;
    score_ = score;
}

void highscores::writeToFile() {
    highscores::playerScore nameScoreStruct;
    nameScoreStruct.name = name_;
    nameScoreStruct.score = score_;
    std::sort(top10_.begin(), top10_.end(), highscores::less_than_score);
    top10_.pop_back();
    top10_.push_back(nameScoreStruct);
    std::sort(top10_.begin(), top10_.end(), highscores::less_than_score);
    std::ofstream outputFile("leaderboard.txt");
    for(auto vectorStruct:top10_) {
        outputFile << vectorStruct.name << vectorStruct.score << "\n";
    }
}

bool highscores::less_than_score(const highscores::playerScore & a, const highscores::playerScore & b) {
    return ((int)a.score > (int)b.score);
}
