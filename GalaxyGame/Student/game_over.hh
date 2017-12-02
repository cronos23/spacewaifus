#ifndef GAME_OVER_HH
#define GAME_OVER_HH

#include <QWidget>
#include <sstream>

namespace Ui {
class game_over;
}

class game_over : public QWidget
{
    Q_OBJECT

public:
    explicit game_over(QWidget *parent = 0);
    ~game_over();
    void setPoints(unsigned int points);
    void setDatedShips(unsigned int datedShips);
    void setRejections(unsigned int rejections);

private:
    Ui::game_over *ui;
};

#endif // GAME_OVER_HH
