#ifndef CONTROLS_HH
#define CONTROLS_HH

#include <QWidget>

namespace Ui {
class controls;
}

class controls : public QWidget
{
    Q_OBJECT

public:
    explicit controls(QWidget *parent = 0);
    ~controls();

private:
    Ui::controls *ui;
};

#endif // CONTROLS_HH
