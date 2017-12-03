#ifndef CONTROLS_HH
#define CONTROLS_HH

#include <QDialog>

namespace Ui {
class controls;
}

/**
 * @brief A simple QDialog used to show tips and controls to the player, accessible to the
 * player via a button in the main menu.
 */
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
