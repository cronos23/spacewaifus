#ifndef PLAYER_SHIP_HH
#define PLAYER_SHIP_HH

#include <algorithm>
#include <iostream>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include <QPainter>


class player_ship: public QObject, public QGraphicsPixmapItem {
Q_OBJECT

public:
    void keyPressEvent(QKeyEvent * event);

//private:
//    int x_pos_;
//    int y_pos_;

signals:
    void shipMoved();
    void shipCollides();

};

#endif // PLAYER_SHIP_HH
