#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    ship_(new player_ship)
{

    std::shared_ptr<Common::IEventHandler> handler = std::make_shared<Student::EventHandler>();
    std::shared_ptr<Student::Galaxy> galaxy = std::make_shared<Student::Galaxy>();
    std::shared_ptr<Common::IGameRunner> gameRunner = Common::getGameRunner(galaxy, handler);
    Common::utilityInit(time(NULL));

    ui->setupUi(this);

    QGraphicsScene * scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));

    std::vector<std::string> starSystemNames = galaxy->getSystemNames();

    for ( auto starSystemName:starSystemNames ) {
        std::shared_ptr<Common::StarSystem> currentStarSystem = galaxy->getStarSystemByName(starSystemName);
        Common::Point coords = currentStarSystem->getCoordinates();
        starsystemobject * starSystem = new starsystemobject;
        int population = currentStarSystem->getPopulation();
        starSystem->setSizeByPop(population);
        starSystem->setOpacity(1);

        starSystem->setPen(QPen(Qt::white));
        starSystem->setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
        starSystem->setRect(coords.x * 200, coords.y * 200, starSystem->getSize(), starSystem->getSize());
        scene->addItem(starSystem);
    }


    ship_->setRect(0,0,30,20);
    ship_->setTransformOriginPoint(15,10);

    scene->addItem(ship_);
    scene->setStickyFocus(true);
    scene->setSceneRect(-20000,-20000,40000,40000);

    ship_->setFlag(QGraphicsItem::ItemIsFocusable);
    ship_->setFocus();

    ui->graphicsView->setTransformationAnchor(GraphicsViewControls::AnchorUnderMouse);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
//    ui->graphicsView->setSceneRect(0, 0, 800, 800);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->centerOn(ship_);
    QObject::connect(ship_, &player_ship::shipMoved, this, &MainWindow::followShip);
    QObject::connect(ship_, &player_ship::shipCollides, this, &MainWindow::checkCollision);

}

MainWindow::~MainWindow()
{

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
