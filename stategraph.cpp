#include "stategraph.h"
namespace States {
    template <class T>
    StateGraph<T>::StateGraph()
    {
        statesAmount = 0;
    }
    template <class T>
    StateGraph<T>::~StateGraph()
    {

    }
    template <class T>
    void StateGraph<T>::restoreConnections(int edge){
        for(int i=0; i<connections.size(); i++){
            int j=0,delInd=-1;
            for(std::vector<int>::iterator itr = connections[i].begin(); itr < connections[i].end(); itr++ ){
                if(*itr == edge){
                    delInd = j;
                    continue;
                }
                if(*itr > edge)
                    connections[i][j] = *itr - 1;
            }
        }

    }
    template <class T>
    int StateGraph<T>::findIndex(State<T>* state){
        for(int i=0; i< states.size(); i++){
            if(state==states[i])
                return i;
        }
        return -1;
    }

    template <class T>
    State<T>* StateGraph<T>::findState(int index){
        if(index < statesAmount)
            return states[index];
        return 0;
    }

    template <class T>
    void StateGraph<T>::addState(State<T> &newState){
        states.push_back(&newState);
        connections.push_back(*(new std::vector<int>()));
    }

    template <class T>
    void StateGraph<T>::addConnection(State<T> &source, State<T> &destination){
        addConnection(findIndex(*source),findIndex(*destination));
    }

    template <class T>
    void StateGraph<T>::addConnection(int srcIndex, int dstIndex){
        if(srcIndex>=0 && srcIndex<0 && dstIndex>=0 && dstIndex<0)
            connections[srcIndex].push_back(dstIndex);
    }

    template <class T>
    void StateGraph<T>::removeState(State<T> &state){
        removeState(findIndex(*state));
    }

    template <class T>
    void StateGraph<T>::removeState(int stateIndex){
        if(stateIndex>=0 && stateIndex <statesAmount){
            states.erase(states.begin() + stateIndex);
            connections.erase(connections.begin() + stateIndex);
            restoreConnections(stateIndex);
        }

    }
}

