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
