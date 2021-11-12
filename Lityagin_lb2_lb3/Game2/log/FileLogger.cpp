#include "FileLogger.h"

FileLogger::FileLogger(const std::string& fileName) {
    output.open(fileName, std::ios_base::out);
    if (output.fail())
    {
        throw std::iostream::failure("Cannot open file: " + fileName);
    }
}
FileLogger::~FileLogger(){
    output.close();
}
void FileLogger::Out(Subject* sub) {
    output << sub;
}

