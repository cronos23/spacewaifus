#ifndef HIGHSCORES_HH
#define HIGHSCORES_HH

#include <QWidget>

namespace Ui {
class highscores;
}

class highscores : public QWidget
{
    Q_OBJECT

public:
    explicit highscores(QWidget *parent = 0);
    ~highscores();

private:
    Ui::highscores *ui;
};

#endif // HIGHSCORES_HH
