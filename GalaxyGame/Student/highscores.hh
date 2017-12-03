#ifndef HIGHSCORES_HH
#define HIGHSCORES_HH

#include <QWidget>
#include <fstream>

namespace Ui {
class highscores;
}

class highscores : public QWidget
{
    Q_OBJECT

public:
    explicit highscores(QWidget *parent = 0);
    ~highscores();
    void readScores();
    void writeScores();

private:
    Ui::highscores *ui;
    struct playerScore
    {
        std::string name;
        unsigned int score;
    };
};

#endif // HIGHSCORES_HH
