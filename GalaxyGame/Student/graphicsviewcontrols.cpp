#include "graphicsviewcontrols.hh"

GraphicsViewControls::GraphicsViewControls(QWidget *parent) : QGraphicsView(parent) {

}

void GraphicsViewControls::wheelEvent(QWheelEvent *event) {

    const qreal factor = 1.1;

    if (event->angleDelta().y() > 0) {
        scale(factor, factor);

    } else {
        scale(1/factor, 1/factor);
    }
}

