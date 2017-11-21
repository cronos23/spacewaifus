#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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


    player_ship * ship = new player_ship();
    ship->setRect(0,0,30,20);
    ship->setTransformOriginPoint(15,10);

    scene->addItem(ship);
    scene->setStickyFocus(true);

    ship->setFlag(QGraphicsItem::ItemIsFocusable);
    ship->setFocus();

   // ui->graphicsView->setTransformationAnchor(GraphicsViewControls::AnchorUnderMouse);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
