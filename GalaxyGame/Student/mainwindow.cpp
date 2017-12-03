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
    props_->getRunner()->spawnShips(100);


    // Setting up graphics
    QGraphicsScene * scene;
    MainWindowUtility util;
    scene = util.createGalaxies(props_->getGalaxy());
    util.setupShip(*ship_);
    util.setupTimers(*frameTimer_, *actionTimer_, *gameTimer_);

    scene->addItem(ship_);

    ui->graphicsView->setTransformationAnchor(GraphicsViewControls::AnchorUnderMouse);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->centerOn(ship_);

    QObject::connect(ship_, &player_ship::shipMoved, this, &MainWindow::followShip);
    QObject::connect(ship_, &player_ship::shipCollides, this, &MainWindow::checkCollision);
    QObject::connect(actionTimer_, &QTimer::timeout, props_, &GameProperties::tick);
    QObject::connect(frameTimer_, &QTimer::timeout, this, &MainWindow::tick);
    QObject::connect(gameTimer_, &QTimer::timeout, this, &MainWindow::GameOver);
    QObject::connect(props_->getHandler(), &Student::EventHandler::distressToggleOn,
                     this, &MainWindow::reactToDistress);
//    QObject::connect(props_->getHandler(), &Student::EventHandler::ExecutionException, this, &MainWindow::testPrint);

    ui->credits_LCD->display(stats_->getCreditBalance());
    ui->lost_LCD->display((int) stats_->getLostShips());
    ui->saved_LCD->display((int) stats_->getSavedShips());
    ui->score_LCD->display((int) stats_->getPoints());

}

MainWindow::~MainWindow()
{

    delete ui;
    delete ship_;
    delete actionTimer_;
    delete frameTimer_;
    delete gameTimer_;
    delete props_;
    delete stats_;
}

void MainWindow::followShip() {
    ui->graphicsView->ensureVisible(ship_, 100, 100);
    ui->coordx_LCD->display(ship_->x() / 200);
    ui->coordy_LCD->display(ship_->y() / 200);
}

void MainWindow::checkCollision() {


    QGraphicsItem* starsystempointer = ship_->collidingItems()[0];
    starsystemobject* starSystem = dynamic_cast<starsystemobject*>(starsystempointer);
    std::shared_ptr<Common::StarSystem> starSystemptr = starSystem->getStarSystem();
    std::string starSystemName = starSystemptr->getName();
    if ( props_->getGalaxy()->getShipsInStarSystem(starSystemName).size() != 0 ) {

        stopTimers();
        encounter *enC = new encounter;
        enC->setStarSystem(starSystemptr);
        enC->exec();
        enC->setStatistics(*stats_);
        ship_->moveBy(100, 100);
        ui->coordx_LCD->display(ship_->x() / 200);
        ui->coordy_LCD->display(ship_->y() / 200);
        gameTimer_->setInterval(remaining_time_on_pause_);
        startTimers();
        props_->getGalaxy()->removeShip(props_->getGalaxy()->getShipsInStarSystem(starSystemptr->getName())[0]);
        props_->getRunner()->spawnShips(1);
        ui->credits_LCD->display(stats_->getCreditBalance());
        ui->lost_LCD->display((int) stats_->getLostShips());
        ui->saved_LCD->display((int) stats_->getSavedShips());
        ui->score_LCD->display((int) stats_->getPoints());

    } else {
        QMessageBox starSystemNoInterest;
        starSystemNoInterest.setText("There seems to be nothing of interest here");
        starSystemNoInterest.exec();
        ship_->moveBy(100, 100);
    }

}

void MainWindow::tick() {

    ui->graphicsView->viewport()->update();

    int minutes;
    int seconds;

    //Convert milliseconds to M:S
    minutes = (gameTimer_->remainingTime() % (1000*60*60)) / (1000*60);
    seconds = ((gameTimer_->remainingTime() % (1000*60*60)) % (1000*60)) / 1000;

    ui->minutes_LCD->display(minutes);
    ui->seconds_LCD->display(seconds);


}

void MainWindow::GameOver() {
    game_over *gameOver = new game_over;
    gameOver->setPoints(stats_->getPoints());
    gameOver->setDatedShips(stats_->getSavedShips());
    gameOver->setRejections(stats_->getLostShips());
    this->close();
    gameOver->show();
}

void MainWindow::reactToDistress(std::shared_ptr<Common::Ship> ship) {
    std::ostringstream distressInfo;
    distressInfo << "Distress signal detected!" <<
                    "\n Location: " << ship->getLocation()->getName() <<
                    "\n Coordinates: " << ship->getLocation()->getCoordinates().x << ", "
                 << ship->getLocation()->getCoordinates().y;
    std::string distressInfostr = distressInfo.str();
    ui->distress_signals->addItem(QString::fromStdString(distressInfostr));
}

void MainWindow::stopTimers() {
    actionTimer_->stop();
    frameTimer_->stop();
    remaining_time_on_pause_ = gameTimer_->remainingTime();
    gameTimer_->stop();
}

void MainWindow::startTimers() {
    actionTimer_->start();
    gameTimer_->start();
    frameTimer_->start();
}

