#include "galaxy.hh"
#include "initialize.hh"
#include "igamerunner.hh"
#include "utility.hh"
#include "eventhandler.hh"
#include "mainwindow.hh"
#include <QApplication>
#include <memory>
#include <time.h>
#include "mainmenu.hh"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MainWindow mainWin;
    mainmenu mainMenu;
    //mainWin.show();
    mainMenu.show();


    return a.exec();
}
