#include "wrongindexstateexception.h"
namespace States {


WrongIndexStateException::WrongIndexStateException()
{
    error = "WrongIndexStateException";
    lastException = this;
}



WrongIndexStateException::WrongIndexStateException(const WrongIndexStateException& e) : StateException(e){

}


WrongIndexStateException::~WrongIndexStateException() throw(){

}

const char* WrongIndexStateException::what() const throw(){
    return error;
}

}
