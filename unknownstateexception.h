#ifndef UNKNOWNSTATEEXCEPTION_H
#define UNKNOWNSTATEEXCEPTION_H
#include "stateexception.h"
namespace States  {



class UnknownStateException : public StateException
{
public:
    UnknownStateException();
    UnknownStateException(const UnknownStateException&);
    virtual ~UnknownStateException() throw();
    virtual const char* what() const throw();
};
}
#endif // UNKNOWNSTATEEXCEPTION_H
