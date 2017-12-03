#ifndef GRAPHICSVIEWCONTROLS_HH
#define GRAPHICSVIEWCONTROLS_HH

#include <QGraphicsView>
#include <QMouseEvent>
#include <QScrollBar>
#include <QWheelEvent>

/**
 * @brief GraphicsViewControls inherits QGraphicsView and adds a zoom-function to it.
 */
class GraphicsViewControls: public QGraphicsView {
public:
    GraphicsViewControls(QWidget*);
    /**
     * @brief Receives QWheelEvents and scales the view accordingly.
     * @param QWheelEvent triggered by the user scrolling with their mouse wheel.
     * @post Exception guarantee: nothrow
     */
    void wheelEvent(QWheelEvent * event);
private:

};

#endif // GRAPHICSVIEWCONTROLS_HH
