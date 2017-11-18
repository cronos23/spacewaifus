//#include "player_ship.hh"

//// acceleration according to engine types
//// deceleration

//void player_ship::keyPressEvent(QKeyEvent *event) {
//    int speedMultiplier;
//    if (event->key() == Qt::Key_Left) {
//        if (QKeyEvent::isAutoRepeat()) {
//            if (speedMultiplier < maximumSpeed_) {
//                ++speedMultiplier;
//            }
//        }
//        else if (speedMultiplier > 0){
//            --speedMultiplier;
//        }
//        setPos(x()-10,y());
//    }
//    else if (event->key() == Qt::Key_Right) {
//        setPos(x()+10,y());
//    }
//    else if (event->key() == Qt::Key_Up) {
//        setPos(x(),y()-10);
//    }
//    else if (event->key() == Qt::Key_Down) {
//        setPos(x(),y()+10);
//}
