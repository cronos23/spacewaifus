#include <QApplication>
#include <memory>
#include <time.h>
#include "galaxy.hh"
#include "initialize.hh"
#include "igamerunner.hh"
#include "utility.hh"
#include "eventhandler.hh"
#include "mainmenu.hh"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mainmenu mainMenu;
    mainMenu.show();

    return a.exec();
}
