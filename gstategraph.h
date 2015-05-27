#ifndef GSTATEGRAPH_H
#define GSTATEGRAPH_H

#include <QGraphicsView>
#include <QDebug>
#include <QMenu>
#include <QScrollBar>

#include "gstate.h"
#include "stategraph.h"
#include "testclass.h"

using namespace States;

class GStateGraph : public QGraphicsView, public StateGraph<testClass>
{
Q_OBJECT
public:
    GStateGraph(QWidget *parent = 0) : QGraphicsView(parent)
    {
        QGraphicsScene *s = new QGraphicsScene(this);
        s->setItemIndexMethod(QGraphicsScene::NoIndex);
        s->setSceneRect(-200, -200, 400, 400);
        setScene(s);

        setCacheMode(CacheBackground);
        setViewportUpdateMode(BoundingRectViewportUpdate);
        setRenderHint(QPainter::Antialiasing);
        setTransformationAnchor(AnchorUnderMouse);
        setMinimumSize(400, 400);

        menu = new QMenu(this);
        menu->addAction("&Добавить состояние");

        connect(menu,
            SIGNAL(triggered(QAction*)),
            SLOT(slotActivated(QAction*))
        );
    }
    ~GStateGraph();

protected:
    virtual void contextMenuEvent(QContextMenuEvent *event);

private:
    QMenu * menu;

public slots:
    void slotActivated(QAction* pAction)
    {
        QString command = pAction->text().remove("&");
        qDebug() << command;

        enum actions {ADD_STATE};

        std::map <std::string, int> mapping;
        mapping["Добавить состояние"] = ADD_STATE;

        switch (mapping[command.toStdString()]) {
        case ADD_STATE:
            GState *state = new GState();
            qDebug() << mapFromGlobal(QCursor::pos() + QPoint(horizontalScrollBar()->value(), verticalScrollBar()->value()));
            state->setPos(mapFromGlobal(QCursor::pos() + QPoint(horizontalScrollBar()->value(), verticalScrollBar()->value())));
            scene()->addItem(state);
            addState(state);
            break;
        }
    }
};

#endif // GSTATEGRAPH_H
