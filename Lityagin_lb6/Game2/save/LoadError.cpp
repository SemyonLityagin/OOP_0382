#include "LoadError.h"


const char *LoadError::getError() {
    return m_error.c_str();
}

LoadError::LoadError(objError obj, Error except) {
    switch(obj){
        case(cellEr):{
            m_error += "cell/";
            break;
        }
        case(heroEr):{
            m_error += "hero/";
            break;
        }
        case(thingEr):{
            m_error += "thing/";
            break;
        }
        case(enemyEr):{
            m_error += "enemy/";
            break;
        }
        default:{
            m_error += "sth wrong with objArg ";
            break;
        }
    }
    switch(except){
        case(typeEr):{
            m_error += "type";
            break;
        }
        case(posEr):{
            m_error += "position";
            break;
        }
        case(hpEr):{
            m_error += "health";
            break;
        }
        case(forceEr):{
            m_error += "force";
            break;
        }
        case(mhpEr):{
            m_error += "max_health";
            break;
        }
        case(coinEr):{
            m_error += "coins";
            break;
        }
        case(numbEr):{
            m_error += "numbers of this object";
            break;
        }
        default:{
            m_error += "sth wrong with errType";
            break;
        }
    }
}
