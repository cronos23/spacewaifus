#ifndef PLAYER_SHIP_HH
#define PLAYER_SHIP_HH

#include <algorithm>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>

/**
 * @brief Creates a graphicsItem that's controlled by the player. Additionally lets
 * it send signals when it moves or collides with a starsystemobject.
 */
class player_ship: public QObject, public QGraphicsPixmapItem {
Q_OBJECT

public:
    /**
     * @brief Implementation of keyboard controls for the graphicsItem.
     * @param Used to read which key was pressed.
     * @post The ships position or rotation has been changed according to which key
     * was pressed.
     */
    void keyPressEvent(QKeyEvent * event);


signals:
    /**
     * @brief Emitted whenever the ship receives a keyEvent that changes it's position
     * or rotation.
     */
    void shipMoved();
    /**
     * @brief Emitted when the ship collides with another graphicsItem. These are always
     * starsystemobjects.
     */
    void shipCollides();

};

#endif // PLAYER_SHIP_HH
