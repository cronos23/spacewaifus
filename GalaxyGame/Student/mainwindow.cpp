#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    ship_(new player_ship),
    frameTimer_(new QTimer),
    actionTimer_(new QTimer),
    props_(new GameProperties)

{

    ui->setupUi(this);

    // Setting up backend

    Common::utilityInit(time(NULL));

    props_->setProperties();

    props_->getRunner()->spawnShips(150);


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
    actionTimer_ ->setInterval(1000); // cargo ship "turn"


    QObject::connect(ship_, &player_ship::shipMoved, this, &MainWindow::followShip);
    QObject::connect(ship_, &player_ship::shipCollides, this, &MainWindow::checkCollision);
    QObject::connect(frameTimer_, &QTimer::timeout, this, &MainWindow::tick);
    QObject::connect(actionTimer_, &QTimer::timeout, props_, &GameProperties::tick);
//    QObject::connect(props_->getHandler(), &Common::IEventHandler::distressOn,
//                     this, &MainWindow::reactToSignal);

    frameTimer_->start();
    actionTimer_->start();

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


    QGraphicsItem* starsystempointer = ship_->collidingItems()[0];
    starsystemobject* starSystem = dynamic_cast<starsystemobject*>(starsystempointer);
    std::shared_ptr<Common::StarSystem> starSystemptr = starSystem->getStarSystem();
    std::string starSystemName = starSystemptr->getName();
    if ( props_->getGalaxy()->getShipsInStarSystem(starSystemName).size() != 0 ) {
        frameTimer_->stop();

        encounter *enC = new encounter;
        enC->setStarSystem(starSystemptr);
        enC->setCorrectAnswer();
        enC->exec();
        ship_->moveBy(100, 100);
        frameTimer_->start();
        props_->getGalaxy()->removeShip(props_->getGalaxy()->getShipsInStarSystem(starSystemptr->getName())[0]);
        props_->getRunner()->spawnShips(1);

    } else {
        QMessageBox starSystemNoInterest;
        starSystemNoInterest.setText("There seems to be nothing of interest here");
        starSystemNoInterest.exec();
        ship_->moveBy(100, 100);
    }

}

void MainWindow::tick() {

    ui->graphicsView->viewport()->update();

}

//void MainWindow::reactToSignal(std::shared_ptr<Common::Ship> ship) {
//    std::cout << "distress signal detected beep boop spoop" << std::endl;
//}

// TODO
// Reaktio distress-signaaliin
// encounterin pisteiden välittäminen statisticsille
// ajastin
// game over
// töttöröö
// asianmukaisesti vaihtuva kuva encounteriin
// galaxyn catchit
