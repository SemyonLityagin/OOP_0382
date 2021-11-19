#include "Decorator.h"

void Decorator::Out(Subject *sub) {
    this->logger->Out(sub);
}

Decorator::~Decorator() {
    delete [] logger;
}

