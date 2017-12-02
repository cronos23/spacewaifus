#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    ship_(new player_ship),
    frameTimer_(new QTimer),
    props_(new GameProperties),
    stats_(new Student::Statistics)

{

    ui->setupUi(this);

    // Setting up backend

    Common::utilityInit(time(NULL));
    props_->setProperties();


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

//    ui->graphicsView->setFocus();
//    frameTimer_->stop();

//    ship_->setFocus();
//    frameTimer->start()
    QGraphicsItem* starsystempointer = ship_->collidingItems()[0];
    starsystemobject* starSystem = dynamic_cast<starsystemobject*>(starsystempointer);
//    std::cout << starSystem->getStarSystem()->getName() << std::endl;
    std::shared_ptr<Common::StarSystem> starSystemptr = starSystem->getStarSystem();
    if ( props_->getGalaxy()->getShipsInStarSystem(starSystemptr->getName()).size() != 0 ) {
        frameTimer_->stop();
//        this->hide();
        encounter *enC = new encounter;
        enC->setStarSystem(starSystemptr);
        enC->setCorrectAnswer();
        enC->exec();
        frameTimer_->start();
//    } else {
//        QMessageBox starSystemNoInterest;
//        starSystemNoInterest.setText("There seems to be nothing of interest here");
//        starSystemNoInterest.exec();
    }

//    std::cout << ship_->collidingItems().size() << std::endl;
//    std::string starSystemName = starSystem->getName();
//    std::cout << starSystem->getStarSystem()->getName() << std::endl;
}

void MainWindow::tick() {
   props_->getRunner()->createActions();
   props_->getRunner()->doActions();
   ui->graphicsView->viewport()->update();

}

