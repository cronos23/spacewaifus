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

void GraphicsViewControls::mousePressEvent(QMouseEvent *event) {

    if (Qt::LeftButton == event->button()) {
        m_pressed = true;
        m_lastMousePos = event->pos();
    }
    QGraphicsView::mousePressEvent(event);
}

void GraphicsViewControls::mouseReleaseEvent(QMouseEvent *event) {

    if (Qt::LeftButton == event->button()) {
        m_pressed = false;
    }

    QGraphicsView::mouseReleaseEvent(event);
}

void GraphicsViewControls::mouseMoveEvent(QMouseEvent *event) {

    if (!m_pressed) {
        return QGraphicsView::mouseMoveEvent(event);
    }
    QPoint diff = m_lastMousePos - event->pos();

    if (QScrollBar *hbar = horizontalScrollBar()) {
        hbar->setValue(hbar->value() + diff.x());
    }
    if (QScrollBar *vbar = verticalScrollBar()) {
        vbar->setValue(vbar->value() + diff.y());
    }
    m_lastMousePos = event->pos();
    return QGraphicsView::mouseMoveEvent(event);
}
