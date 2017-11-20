#ifndef PLAYER_SHIP_HH
#define PLAYER_SHIP_HH

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QPainter>
#include <algorithm>
#include <iostream>

class player_ship: public QGraphicsRectItem {
public:
    void keyPressEvent(QKeyEvent * event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PLAYER_SHIP_HH
