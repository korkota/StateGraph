#ifndef LOGGER_CPP
#define LOGGER_CPP
#include "QFile"
#include "QTextStream"
#include <string.h>
namespace Logger{

    QFile* logFile = new QFile("SGRPHLog.log");

    void setLogFile(QString file){
        logFile = new QFile(file);
    }

    void write(QString data){
        if(logFile->open(QIODevice::Append)){
            QTextStream out(logFile);
            out << data << "\n";
            logFile->close();
        }
    }
}
#endif //LOGGER_CPP
