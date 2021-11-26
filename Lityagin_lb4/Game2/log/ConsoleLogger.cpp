#include "ConsoleLogger.h"

void ConsoleLogger::Out(Subject* sub) {
    Decorator::Out(sub);
    std::cout << sub;
}

ConsoleLogger::~ConsoleLogger() {
    delete [] logger;
}
