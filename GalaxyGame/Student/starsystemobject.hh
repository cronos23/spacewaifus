#ifndef STARSYSTEMOBJECT_HH
#define STARSYSTEMOBJECT_HH

#include <QGraphicsEllipseItem>
#include <QPainter>
#include <vector>

class starsystemobject: public QGraphicsEllipseItem {

public:

    QRectF boundingRect() const;
    void setSizeByPop(int population);
    int getSize();
private:
    int starsystemsize_;
};

#endif // STARSYSTEMOBJECT_HH
