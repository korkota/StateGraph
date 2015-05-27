#ifndef GSTATE_H
#define GSTATE_H

#include <QGraphicsItem>

#include "state.h"
#include "testclass.h"

using namespace States;

class GState : public QGraphicsItem, public State<testClass>
{
public:
    GState(QGraphicsItem *parent = 0);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    ~GState();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;


};

#endif // GSTATE_H
