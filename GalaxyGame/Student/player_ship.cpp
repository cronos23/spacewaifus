#include "player_ship.hh"



void player_ship::keyPressEvent(QKeyEvent *event) {

    if (event->key() == Qt::Key_Left) {
        this->setRotation(this->rotation()-10);

    } else if (event->key() == Qt::Key_Right) {
        this->setRotation(this->rotation()+10);

    } else if (event->key() == Qt::Key_Up) {

        setPos(x()-cos(this->rotation()*3.14/180)*15,y()-sin(this->rotation()*3.14/180)*15);
    }
    emit shipMoved();

    if (collidingItems().size() != 0) {
        emit shipCollides();
    }
}


