#ifndef STATE_H
#define STATE_H
#include <vector>
#include <stategraph.h>
#include <QString>
namespace States {

    template <class V>
    class StateGraph;

    template <class T>
    class State
    {
        friend class StateGraph<T>;
    protected:

        T data;
        bool marked;

        void swap(State<T> & other){
            std::swap(data,other.data);
        }

    public:


        T getData(){
            return data;
        }
        void setData(T data){
            this->data = data;
        }


        virtual QString toString(){
            return "State";
        }


     //   Iterator getConnectedNodes();
        State<T>& operator = (State<T> other){
            swap(other);
            return *this;
        }

        State(){
            marked = false;
        }



        State(State<T> &state){
            this->data = state.data;
            marked = false;
        }

        State(T data){
            this->data = data;
            marked = false;
        }

        ~State(){

        }
    };
}
#endif // STATE_H
