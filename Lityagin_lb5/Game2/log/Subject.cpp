#include "Subject.h"

void Subject::SetObs(Observer* obs){
    this->observer = obs;
}
void Subject::Notify(){
    if(observer == nullptr){
        std::cout<< "Subject doesn't have observer";
    }
    else{
        observer->Update();
    }
}

std::ostream &operator<<(std::ostream &out, Subject* sub) {
    out << sub->GetLog() << std::endl;
    return out;
}

