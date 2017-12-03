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
        std::ostringstream toolTipInfo;
        toolTipInfo << currentStarSystem->getName() << "\n"
                    << "Coordinates: " << currentStarSystem->getCoordinates().x
                    << ", " << currentStarSystem->getCoordinates().y
                    << "\n" << "Population: " << currentStarSystem->getPopulation() <<
                       "\n" << "Type of possible waifu: " << getWaifuType(currentStarSystem->getEconomy());
        std::string toolTipInfostr = toolTipInfo.str();
        starSystem->setToolTip(QString::fromStdString(toolTipInfostr));
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

void MainWindowUtility::setupTimers(QTimer &frametimer, QTimer &actiontimer, QTimer &gametimer) {
    frametimer.setInterval(16); // Locked refresh rate
    actiontimer.setInterval(2500); // cargo ship "turn"
    gametimer.setSingleShot(true);
    gametimer.setInterval(180000);
}

std::string MainWindowUtility::getWaifuType(Common::StarSystem::ECONOMY_TYPE econ_type) {
    std::map<Common::StarSystem::ECONOMY_TYPE, std::string> waifu_types;

    waifu_types[Common::StarSystem::ECONOMY_TYPE::Terraforming] = "Dandere";
    waifu_types[Common::StarSystem::ECONOMY_TYPE::Refinery] = "Wealthy";
    waifu_types[Common::StarSystem::ECONOMY_TYPE::Extraction] = "Yandere";
    waifu_types[Common::StarSystem::ECONOMY_TYPE::Colony] = "Kuudere";
    waifu_types[Common::StarSystem::ECONOMY_TYPE::HiTech] = "Kamidere";
    waifu_types[Common::StarSystem::ECONOMY_TYPE::Industrial] = "Greedy";
    waifu_types[Common::StarSystem::ECONOMY_TYPE::Tourism] = "Greedy";
    waifu_types[Common::StarSystem::ECONOMY_TYPE::Agriculture] = "Deredere";
    waifu_types[Common::StarSystem::ECONOMY_TYPE::Service] = "Deredere";
    waifu_types[Common::StarSystem::ECONOMY_TYPE::Military]= "Tsundere";
    waifu_types[Common::StarSystem::ECONOMY_TYPE::None] = "Special";

    return waifu_types[econ_type];
}
