#ifndef STATE_H
#define STATE_H
#include <vector>
#include <stategraph.h>
namespace States {

    template <class V>
    class StateGraph;

    template <class T>
    class State
    {
    private:

        std::vector< State<T> > connections;
        T data;
        StateGraph<T> innerGraph;
        void swap(State<T> & other){
            std::swap(data,other.data);
        }

    public:


        T getData(){
            return data;
        }
        void setData(T data){

        }

     //   Iterator getConnectedNodes();
        State<T>& operator = (State<T> other){
            swap(other);
            return *this;
        }

        State(){

        }



        State(State<T> &state){
            this->data = state.data;
        }

        State(T data){
            this->data = data;
        }

        ~State(){

        }
    };
}
#endif // STATE_H
