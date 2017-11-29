#ifndef STARSYSTEMOBJECT_HH
#define STARSYSTEMOBJECT_HH

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QPainter>
#include <vector>
#include "starsystem.hh"

class starsystemobject: public QObject, public QGraphicsEllipseItem {

public:

    QRectF boundingRect() const;
    void setSizeByPop();
    int getSize();
    void setStarSystem(std::shared_ptr<Common::StarSystem> starSystem);
    std::string getName();
private:
    int starsystemsize_;
    std::shared_ptr<Common::StarSystem> starsystemptr_;
};

#endif // STARSYSTEMOBJECT_HH
