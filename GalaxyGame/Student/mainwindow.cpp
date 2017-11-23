#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    ship_(new player_ship),
    timer_(new QTimer)
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

        starSystem->setPen(QPen(Qt::yellow));
        starSystem->setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
        starSystem->setRect(coords.x * 200, coords.y * 200, starSystem->getSize(), starSystem->getSize());
        scene->addItem(starSystem);
    }


    ship_->setRect(0,0,30,20);
    ship_->setTransformOriginPoint(15,10);

    scene->addItem(ship_);
    scene->setStickyFocus(true);
//    scene->setSceneRect(0,0,00,2000);

    ship_->setFlag(QGraphicsItem::ItemIsFocusable);
    ship_->setFocus();

//    ui->graphicsView->setResizeAnchor(GraphicsViewControls::AnchorUnderMouse);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
//    ui->graphicsView->setSceneRect(0,0,200,200);
    ui->graphicsView->setScene(scene);
    QObject::connect(timer_, &QTimer::timeout , this, &MainWindow::followShip );
    timer_->start(10);

}

MainWindow::~MainWindow()
{
    delete timer_;
    delete ship_;
    delete ui;
}

void MainWindow::followShip() {
//    ui->graphicsView->ensureVisible(ui->graphicsView->sceneRect(), 50, 50);
    ui->graphicsView->centerOn(ship_);
}

