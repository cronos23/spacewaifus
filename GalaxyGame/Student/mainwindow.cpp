#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    ship_(new player_ship),
    frameTimer_(new QTimer),
    props_(new GameProperties)

{

    ui->setupUi(this);

    // Setting up backend

    props_->setProperties();
    Common::utilityInit(time(NULL));
    props_->getRunner()->spawnShips(20);


    // Setting up graphics
    QGraphicsScene * scene;
    MainWindowUtility util;
    scene = util.createGalaxies(props_->getGalaxy());
    util.setupShip(*ship_);

    scene->addItem(ship_);

    ui->graphicsView->setTransformationAnchor(GraphicsViewControls::AnchorUnderMouse);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->centerOn(ship_);

    frameTimer_->setInterval(16); // Locked refresh rate


    QObject::connect(ship_, &player_ship::shipMoved, this, &MainWindow::followShip);
    QObject::connect(ship_, &player_ship::shipCollides, this, &MainWindow::checkCollision);
    QObject::connect(frameTimer_, &QTimer::timeout, this, &MainWindow::tick);

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

//    ui->graphicsView->setFocus();
//    frameTimer_->stop();
    frameTimer_->stop();
    this->hide();

//    ship_->setFocus();
//    frameTimer->start()
    QGraphicsItem* starsystempointer = ui->graphicsView->scene()->itemAt(ship_->collidingItems()[0]->pos(), QTransform());
    starsystemobject* starSystem = dynamic_cast<starsystemobject*>(starsystempointer);
    std::shared_ptr<Common::StarSystem> starSystemptr = starSystem->getStarSystem();
    encounter *enC = new encounter;
    enC->setStarSystem(starSystemptr);
    enC->show();


//    std::cout << ship_->collidingItems().size() << std::endl;
//    std::string starSystemName = starSystem->getName();
//    std::cout << starSystem->getStarSystem()->getName() << std::endl;
}

void MainWindow::tick() {
   props_->getRunner()->createActions();
   props_->getRunner()->doActions();
   ui->graphicsView->viewport()->update();

}

