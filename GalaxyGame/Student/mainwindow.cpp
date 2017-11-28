#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    ship_(new player_ship),
    frameTimer_(new QTimer)

{

    std::shared_ptr<Common::IEventHandler> handler = std::make_shared<Student::EventHandler>();
    std::shared_ptr<Student::Galaxy> galaxy = std::make_shared<Student::Galaxy>();
    std::shared_ptr<Common::IGameRunner> gameRunner = Common::getGameRunner(galaxy, handler);
    Common::utilityInit(time(NULL));
    ui->setupUi(this);


    QGraphicsScene * scene;


    // Setting up
    MainWindowUtility util;
    scene = util.createGalaxies(galaxy);
    util.setupShip(*ship_);

    scene->addItem(ship_);

    ui->graphicsView->setTransformationAnchor(GraphicsViewControls::AnchorUnderMouse);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->centerOn(ship_);

    frameTimer_->setInterval(17); // Locked refresh rate

    QObject::connect(ship_, &player_ship::shipMoved, this, &MainWindow::followShip);
    QObject::connect(ship_, &player_ship::shipCollides, this, &MainWindow::checkCollision);
    QObject::connect(frameTimer_, &QTimer::timeout, this, &MainWindow::renderFrame);

    frameTimer_->start();

}

MainWindow::~MainWindow()
{

    delete frameTimer_;
    delete ship_;
    delete ui;
}

void MainWindow::followShip() {
    ui->graphicsView->ensureVisible(ship_, 100, 100);
}

void MainWindow::checkCollision() {
//    std::string waifu_type = ship_->collidingItems()[0];
//    ui->graphicsView->setViewportUpdateMode(QGraphicsView::NoViewportUpdate);
//    ui->graphicsView->setFocus();
//    launch dialog
//    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
//    ship_->setFocus();
    std::cout << "kutsuit mua lul" << std::endl;
}

void MainWindow::renderFrame() {
   ui->graphicsView->viewport()->update();
}
