#ifndef GRAPHICSVIEWCONTROLS_HH
#define GRAPHICSVIEWCONTROLS_HH

#include <QGraphicsView>
#include <QMouseEvent>
#include <QScrollBar>
#include <QWheelEvent>

class GraphicsViewControls: public QGraphicsView {
public:
    GraphicsViewControls(QWidget*);
    void wheelEvent(QWheelEvent * event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
private:
    bool m_pressed;
    QPoint m_lastMousePos;
};

#endif // GRAPHICSVIEWCONTROLS_HH
