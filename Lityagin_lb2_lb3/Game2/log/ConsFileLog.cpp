#include "ConsFileLog.h"

ConsFileLog::ConsFileLog(const std::string& fileName) {
    output.open(fileName, std::ios_base::out);
    if (output.fail())
    {
        throw std::iostream::failure("Cannot open file: " + fileName);
    }
}
ConsFileLog::~ConsFileLog(){
    output.close();
}
void ConsFileLog::Out(Subject* sub) {
    output << sub;
    std::cout << sub;
}

