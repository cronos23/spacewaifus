#include "mainwindowutility.hh"

MainWindowUtility::MainWindowUtility() {

}

QGraphicsScene* MainWindowUtility::createGalaxies(std::shared_ptr<Student::Galaxy> galaxy) {

    QGraphicsScene * scene = new QGraphicsScene();

    std::vector<std::string> starSystemNames = galaxy->getSystemNames();

    for ( auto starSystemName:starSystemNames ) {
        std::shared_ptr<Common::StarSystem> currentStarSystem = galaxy->getStarSystemByName(starSystemName);
        Common::Point coords = currentStarSystem->getCoordinates();
        starsystemobject * starSystem = new starsystemobject;
        starSystem->setStarSystem(currentStarSystem);
        starSystem->setSizeByPop();
        starSystem->setOpacity(1);
        starSystem->setZValue(1);

        starSystem->setPen(QPen(Qt::white));
        starSystem->setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
        starSystem->setRect(0, 0, starSystem->getSize(), starSystem->getSize());
        starSystem->setPos(coords.x * 200, coords.y * 200);
        scene->addItem(starSystem);
        scene->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));
        scene->setStickyFocus(true);
        scene->setSceneRect(-10000,-10000,20000,20000);
    }

    return scene;
}

void MainWindowUtility::setupShip(player_ship &ship) {
    QPixmap playerShipPixmap;
    playerShipPixmap.load(":/images/images/player_ship.png");

    ship.setZValue(2);
    ship.setTransformOriginPoint(playerShipPixmap.width()/2, playerShipPixmap.height()/2);
    ship.setFlag(QGraphicsItem::ItemIsFocusable);
    ship.setFocus();
    ship.setPixmap(playerShipPixmap);
    ship.setPos(100, 100);
}
