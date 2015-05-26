#include "stateexception.h"
namespace States {

StateException* StateException::lastException;

StateException::StateException() : std::exception()
{
    lastException = this;
    error = "StateException";
}

StateException::~StateException() throw()
{

}


StateException::StateException(const StateException& e) : std::exception(e){
    this->error = e.error;
}

StateException& StateException::operator= (const StateException& e){
    this->error = e.error;
    return *this;
}

const char* StateException::what() const throw() {
    return error;
}

StateException* StateException::getLastException(){
    return lastException;
}
}
