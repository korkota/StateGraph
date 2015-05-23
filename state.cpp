#include "state.h"
namespace States {
    template <class T>
    State<T>::State()
    {

    }
    template <class T>
    State<T>::~State()
    {

    }

    template <class T>
    State<T>& State<T>::operator = (State<T> other){
        swap(other);
        return *this;
    }

    template <class T>
    State<T>::State(T data){
        this->data = data;
    }

    template <class T>
    State<T>::State(State<T> &state){
        this->data = state.data;
    }


    template <class T>
    T State<T>::getData(){
        return data;
    }

    template <class T>
    void State<T>::setData(const T data){

    }

 //   Iterator getConnectedNodes();

}

