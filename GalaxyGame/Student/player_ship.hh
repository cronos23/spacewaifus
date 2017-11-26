#ifndef PLAYER_SHIP_HH
#define PLAYER_SHIP_HH

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
#include <QPainter>
#include <algorithm>
#include <iostream>


class player_ship: public QObject, public QGraphicsRectItem {
Q_OBJECT

public:
    void keyPressEvent(QKeyEvent * event);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
    void shipMoved();
    void shipCollides();

};

#endif // PLAYER_SHIP_HH
