#include <QMenu>
#include <QContextMenuEvent>
#include <QDebug>

#include "gstategraph.h"
#include "gstate.h"

void GStateGraph::contextMenuEvent(QContextMenuEvent *event)
{
    menu->exec(event->globalPos());
}

GStateGraph::~GStateGraph()
{

}

