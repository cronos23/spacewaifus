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

    std::vector<std::string> starSystemNames = galaxy->getSystemNames();

    for ( auto starSystemName:starSystemNames ) {
        std::shared_ptr<Common::StarSystem> currentStarSystem = galaxy->getStarSystemByName(starSystemName);
        Common::Point coords = currentStarSystem->getCoordinates();
        starsystemobject * starSystem = new starsystemobject;
        starSystem->setRect(coords.x * 100, coords.y * 100, 100, 100);
        scene->addItem(starSystem);
    }


    player_ship * ship = new player_ship();
    ship->setRect(0,0,100,100);
    ship->setTransformOriginPoint(50,50);

    scene->addItem(ship);
    scene->setStickyFocus(true);

    ship->setFlag(QGraphicsItem::ItemIsFocusable);
    ship->setFocus();

    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
