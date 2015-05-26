#ifndef SUPERSTATE_H
#define SUPERSTATE_H

#include <state.h>
#include <stategraph.h>
#include <QString>
namespace States {

template <class T>
class SuperState : public State<T>
{

    StateGraph<T> * innerGraph;

public:

    void setInnerGraph(StateGraph<T>* graph){
        innerGraph = graph;
    }

    StateGraph<T>* getInnerGraph(){
        return innerGraph;
    }

    virtual QString toString(){
        return "SuperState";
    }

    QString serialize(){
        QDomNode el = serializeToDom();
        QDomDocument doc = el.toDocument();
        return doc.toString() ;

    }

    QDomNode serializeToDom(){
        QDomDocument doc = State<T>::serializeToDom().toDocument();
        doc.firstChildElement().setTagName("SuperState");
        QDomElement node2 = doc.createElement("Graph");
        QDomNode graphNode;
        if(innerGraph!= 0){
            graphNode = innerGraph->serializeToDom();
            node2.appendChild(graphNode);
        }
        else
            node2.appendChild(doc.createTextNode("0"));
        doc.firstChildElement().appendChild(node2);
        return doc;
    }

    SuperState(){
        innerGraph = 0;
    }

    SuperState(T data): State<T>(data){
        innerGraph = 0;
    }

    SuperState(SuperState<T> &ss): State<T>(ss){
        innerGraph = 0;

    }

    SuperState<T>& operator = (State<T> other){
        swap(other);
        return *this;
    }

    ~SuperState();


};
}
#endif // SUPERSTATE_H
