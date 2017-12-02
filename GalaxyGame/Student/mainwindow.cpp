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
        enC->setCorrectAnswer();
        enC->exec();
        enC->setStatistics(*stats_);
        ship_->moveBy(100, 100);
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
    if (gameTimer_->remainingTime() >= 0) {

        //Convert milliseconds to M:S
        minutes = (gameTimer_->remainingTime() % (1000*60*60)) / (1000*60);
        seconds = ((gameTimer_->remainingTime() % (1000*60*60)) % (1000*60)) / 1000;

        ui->minutes_LCD->display(minutes);
        ui->seconds_LCD->display(seconds);

        if (gameTimer_->remainingTime() <= 0) {
            GameOver();
        }
    } else {
        GameOver();
    }
}

void MainWindow::GameOver() {
    game_over *gameOver = new game_over;
    gameOver->setPoints(stats_->getPoints());
    gameOver->setDatedShips(stats_->getSavedShips());
    gameOver->setRejections(stats_->getLostShips());
    gameOver->show();
}

void MainWindow::reactToDistress(std::shared_ptr<Common::Ship> ship) {
    std::ostringstream distressInfo;
    distressInfo << "Distress signal detected!" <<
                    "\n Location: " << ship->getLocation()->getName();
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

// TODO
// ajastin
// game over
// galaxyn catchit???
