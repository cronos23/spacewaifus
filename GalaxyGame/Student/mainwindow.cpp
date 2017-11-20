#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene * scene = new QGraphicsScene();

    player_ship * ship = new player_ship();
    ship->setRect(0,0,100,100);
    ship->setTransformOriginPoint(50,50);

    scene->addItem(ship);

    ship->setFlag(QGraphicsItem::ItemIsFocusable);
    ship->setFocus();

    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
