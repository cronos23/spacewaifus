#ifndef MAINMENU_HH
#define MAINMENU_HH

#include <QWidget>

namespace Ui {
class mainmenu;
}

class mainmenu : public QWidget
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = 0);
    ~mainmenu();

private:
    Ui::mainmenu *ui;
};

#endif // MAINMENU_HH