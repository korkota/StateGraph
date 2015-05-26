#ifndef WRONGINDEXSTATEEXCEPTION_H
#define WRONGINDEXSTATEEXCEPTION_H
#include "stateexception.h"

namespace States {


class WrongIndexStateException : public StateException
{
public:
    WrongIndexStateException();
    WrongIndexStateException(const WrongIndexStateException&);
    virtual ~WrongIndexStateException() throw();
    virtual const char* what() const throw();
};
}
#endif // WRONGINDEXSTATEEXCEPTION_H
