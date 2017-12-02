#ifndef CONTROLS_HH
#define CONTROLS_HH

#include <QDialog>

namespace Ui {
class controls;
}

class controls : public QDialog
{
    Q_OBJECT

public:
    explicit controls(QWidget *parent = 0);
    ~controls();

private:
    Ui::controls *ui;
};

#endif // CONTROLS_HH
