#ifndef STATEGRAPH_H
#define STATEGRAPH_H

#include <vector>
#include <state.h>
#include <iterator>
namespace States {
    template <class V>
    class State;

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
                }
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

        void addState(State<T> &newState){
            states.push_back(&newState);
            connections.push_back(*(new std::vector<int>()));
        }


        void addConnection(State<T> &source, State<T> &destination){
            addConnection(findIndex(*source),findIndex(*destination));
        }

        void addConnection(int srcIndex, int dstIndex){
            if(srcIndex>=0 && srcIndex<0 && dstIndex>=0 && dstIndex<0)
                connections[srcIndex].push_back(dstIndex);
        }

        void removeState(State<T> &state){
            removeState(findIndex(*state));
        }

        void removeState(int stateIndex){
            if(stateIndex>=0 && stateIndex <statesAmount){
                states.erase(states.begin() + stateIndex);
                connections.erase(connections.begin() + stateIndex);
                restoreConnections(stateIndex);
            }

        }
      //Iterator getConnections(int stateIndex);
      //Iterator getConnections(State<T> &state);

        StateGraph();
        ~StateGraph();
    };
}
#endif // STATEGRAPH_H
