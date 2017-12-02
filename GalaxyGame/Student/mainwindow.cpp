#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    ship_(new player_ship),
    actionTimer_(new QTimer),
    frameTimer_(new QTimer),
    gameTimer_(new QTimer),
    props_(new GameProperties),
    stats_(new Student::Statistics)

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
    actionTimer_ ->setInterval(15000); // cargo ship "turn"
    gameTimer_->setSingleShot(true);
    gameTimer_->setInterval(360000);


    QObject::connect(ship_, &player_ship::shipMoved, this, &MainWindow::followShip);
    QObject::connect(ship_, &player_ship::shipCollides, this, &MainWindow::checkCollision);
    QObject::connect(actionTimer_, &QTimer::timeout, props_, &GameProperties::tick);
    QObject::connect(frameTimer_, &QTimer::timeout, this, &MainWindow::tick);
    QObject::connect(gameTimer_, &QTimer::timeout, this, &MainWindow::GameOver);
    QObject::connect(props_->getHandler(), &Student::EventHandler::distressToggleOn,
                     this, &MainWindow::reactToDistress);


    ui->credits_LCD->display(stats_->getCreditBalance());
    ui->lost_LCD->display((int) stats_->getLostShips());
    ui->saved_LCD->display((int) stats_->getSavedShips());
    ui->score_LCD->display((int) stats_->getPoints());

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

void MainWindow::GameOver() {
//    GameOver *gameOver = new GameOver;
//    gameOver->setPoints(stats_->getPoints());
//    gameOver->setWaifus(stats_->getSavedShips());
//    gameOver->show();
}

void MainWindow::reactToDistress(std::shared_ptr<Common::Ship> ship) {
    std::ostringstream distressInfo;
    distressInfo << "Distress signal detected!" <<
                    "\n Location: " << ship->getLocation()->getName();
    std::string distressInfostr = distressInfo.str();
    ui->distress_signals->addItem(QString::fromStdString(distressInfostr));
}

//void MainWindow::reactToStoppedDistress(std::shared_ptr<Common::Ship> ship) {

//}

void MainWindow::startTimers() {
    actionTimer_->start();
    frameTimer_->start();
    gameTimer_->start();
}

// TODO
// encounterin pisteiden välittäminen statisticsille
// ajastin
// game over
// töttöröö
// asianmukaisesti vaihtuva kuva encounteriin
// galaxyn catchit
