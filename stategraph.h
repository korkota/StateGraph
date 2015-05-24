#ifndef STATEGRAPH_H
#define STATEGRAPH_H

#include <vector>
#include <state.h>
#include <iterator>
#include <stateiterator.h>
namespace States {
    template <class V>
    class State;

    template <class D>
    class StateIterator;

    template <class T>
    class StateGraph
    {


        State<T>* initialS;
        State<T>* finalS;
        std::vector< State<T>* > states;
        std::vector< std::vector<int> > connections;
        int statesAmount;

        void restoreConnections(int edge){
            for(int i=0; i<connections.size(); i++){
                int j=0,delInd=-1;
                for(std::vector<int>::iterator itr = connections[i].begin(); itr < connections[i].end(); itr++ ){
                    if(*itr == edge){
                        delInd = j;
                        continue;
                    }
                    if(*itr > edge)
                        connections[i][j] = *itr - 1;
                    j++;
                }
                if(delInd != -1)
                    connections[i].erase(connections[i].begin() + delInd);
            }
        }


        int findIndex(State<T>* state){
            for(int i=0; i< states.size(); i++){
                if(state==states[i])
                    return i;
            }
            return -1;
        }

        State<T>* findState(int index){
            if(index < statesAmount)
                return states[index];
            return 0;
        }

    public:
        typedef StateIterator<T> iterator ;
        void setInitialState(State<T> *newState)
        {
            if(findIndex(newState) == -1 )
                addState(newState);
            initialS = newState;
        }

        void setFinalState(State<T> *newState){
            if(findIndex(newState) == -1 )
                addState(newState);
            finalS = newState;
        }

        bool isInitialState(State<T>* state){
            return *state==initialS ? true : false;
        }

        bool isFinalState(State<T>* state){
            return *state==finalS ? true : false;
        }

        void addState(State<T>* newState){
            states.push_back(newState);
            connections.push_back(*(new std::vector<int>()));
            statesAmount++;
        }


        void addConnection(State<T>* source, State<T>* destination){
            addConnection(findIndex(source),findIndex(destination));
        }

        void addConnection(int srcIndex, int dstIndex){
            if(srcIndex>=0 && srcIndex<statesAmount && dstIndex>=0 && dstIndex<statesAmount)
                connections[srcIndex].push_back(dstIndex);
        }

        void removeState(State<T>* state){
            removeState(findIndex(state));
        }

        void removeState(int stateIndex){
            if(stateIndex>=0 && stateIndex <statesAmount){
                states.erase(states.begin() + stateIndex);
                connections.erase(connections.begin() + stateIndex);
                restoreConnections(stateIndex);
            }

        }

        iterator begin(){
            StateIterator<T> iter(states);
            return iter;

        }


        iterator getConnections(State<T> *state){
            return getConnections(findIndex(state));
        }

        iterator getConnections(int stateIndex){
            std::vector< State<T>* > data;
            for(int i = 0 ;  i < connections[stateIndex].size(); i++){
                data.push_back(findState(connections[stateIndex][i]));
            }
            return data;
        }

        void removeConnection(State<T>* source, State<T>* destination){
            removeConnection(findIndex(source),findIndex(destination));
        }

        void removeConnection(int source, int destination){
            if(!(source>=0 && source<statesAmount && destination>=0 && destination<statesAmount))
                return;
            int toDel = -1;
            for(int i = 0 ;  i < connections[source].size(); i++){
                if(connections[source][i] == destination){
                    toDel = i;
                    break;
                }
            }
            if(toDel != -1)
                connections[source].erase(connections[source].begin() + toDel);
        }

        StateGraph(){
            statesAmount = 0;
        }
        ~StateGraph(){

        }
    };
}
#endif // STATEGRAPH_H
