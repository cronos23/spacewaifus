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

<<<<<<< HEAD
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));

    std::vector<std::string> starSystemNames = galaxy->getSystemNames();

    for ( auto starSystemName:starSystemNames ) {
        std::shared_ptr<Common::StarSystem> currentStarSystem = galaxy->getStarSystemByName(starSystemName);
        Common::Point coords = currentStarSystem->getCoordinates();
        starsystemobject * starSystem = new starsystemobject;
        int population = currentStarSystem->getPopulation();
        starSystem->setSizeByPop(population);
        starSystem->setStarSystem(currentStarSystem);
        starSystem->setOpacity(1);
        starSystem->setZValue(1);

        starSystem->setPen(QPen(Qt::white));
        starSystem->setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
        starSystem->setRect(0, 0, starSystem->getSize(), starSystem->getSize());
        starSystem->setPos(coords.x * 200, coords.y * 200);
        scene->addItem(starSystem);
    }

    QPixmap myPixMap;
    myPixMap.load(":/images/images/player_ship.png");


    ship_->setZValue(2);

    ship_->setTransformOriginPoint(myPixMap.width()/2, myPixMap.height()/2);


    scene->addItem(ship_);
    scene->setStickyFocus(true);
    scene->setSceneRect(-10000,-10000,20000,20000);
=======
    QGraphicsScene * scene;
>>>>>>> 897c255630b241ba7a62b2907d97749b68e1fe17

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
