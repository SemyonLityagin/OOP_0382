#include "FileLogger.h"

FileLogger::~FileLogger(){
    output.close();
    delete [] logger;
}
void FileLogger::Out(Subject* sub) {
    Decorator::Out(sub);
    output << sub;
}

