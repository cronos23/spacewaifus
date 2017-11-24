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
private:

};

#endif // GRAPHICSVIEWCONTROLS_HH
