#include "player_ship.hh"


void player_ship::keyPressEvent(QKeyEvent *event) {

    if (event->key() == Qt::Key_Left) {
        this->setRotation(this->rotation()-10);

    } else if (event->key() == Qt::Key_Right) {
        this->setRotation(this->rotation()+10);

    } else if (event->key() == Qt::Key_Up) {

        setPos(x()-cos(this->rotation()*3.14/180)*8,y()-sin(this->rotation()*3.14/180)*8);
    }
}

QRectF player_ship::boundingRect() const {
    return QRectF(0, 0, 100, 100);
}

void player_ship::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->fillRect(boundingRect(), Qt::red);
}
