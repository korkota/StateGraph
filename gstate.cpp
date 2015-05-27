#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsSceneMouseEvent>
#include <QtGui/QPainter>
#include <QtGui/QStyleOption>

#include "gstate.h"

GState::GState(QGraphicsItem *parent) : QGraphicsItem(parent)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setFlag(ItemIsSelectable);
    setAcceptHoverEvents(true);
    setCacheMode(DeviceCoordinateCache);
    setZValue(1); // higher than the edge
}


QRectF GState::boundingRect() const
{
    qreal adjust = 2;
    return QRectF( -10 - adjust, -10 - adjust,
                  23 + adjust, 23 + adjust);
}

QPainterPath GState::shape() const
{
    QPainterPath path;
    path.addEllipse(-10, -10, 20, 20);
    return path;
}

void GState::paint(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget *)
{
    QRadialGradient gradient(-3, -3, 10);
    if (isSelected()) {
      gradient.setCenter(3, 3);
      gradient.setFocalPoint(3, 3);
      gradient.setColorAt(0, Qt::red);
      gradient.setColorAt(1, Qt::darkRed);
    } else if (option->state & QStyle::State_MouseOver) {
      gradient.setColorAt(0, Qt::green);
      gradient.setColorAt(1, Qt::darkGreen);
    } else {
      gradient.setColorAt(0, Qt::yellow);
      gradient.setColorAt(1, Qt::darkYellow);
    }

    painter->setBrush(gradient);
    painter->setPen(QPen(Qt::black, 0));
    painter->drawEllipse(-10, -10, 20, 20);
}


void GState::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void GState::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

GState::~GState()
{

}

