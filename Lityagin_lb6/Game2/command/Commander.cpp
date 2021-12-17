#include "Commander.h"

Command Commander::Moving(sf::Event event) {
    if(event.type == sf::Event::Closed) {
        return close;
    }
    if(event.type == sf::Event::MouseButtonPressed && !pressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            int cx = event.mouseButton.x;
            int cy = event.mouseButton.y;
            if (Size * 40 <= cx && cx <= Size * 40 + 40 && Size * 40 - 120 <= cy && cy <= Size * 40-80) {
                return save1;
            }
            if (Size * 40 <= cx && cx <= Size * 40 + 40 && Size * 40 - 80 <= cy && cy <= Size * 40-40) {
                return save;
            }
            if (Size * 40 + 80 < cx && cx <= Size * 40 + 120 && Size * 40 - 120 <= cy && cy <= Size * 40-80) {
                return load1;
            }
            if (Size * 40 + 80 < cx && cx <= Size * 40 + 120 && Size * 40 - 80 <= cy && cy <= Size * 40-40) {
                return load;
            }
            if (Size * 40 <= cx && cx <= Size * 40 + 40 && Size * 40 - 40 <= cy && cy <= Size * 40) {
                pressed = true;
                return moveLeft;
            }
            if (Size * 40 + 40 < cx && cx <= Size * 40 + 80 && Size * 40 - 80 <= cy && cy < Size * 40 - 40) {
                pressed = true;
                return moveUp;
            }
            if (Size * 40 + 40 < cx && cx <= Size * 40 + 80 && Size * 40 - 40 <= cy && cy <= Size * 40) {
                pressed = true;
                return moveDown;
            }
            if (Size * 40 + 80 < cx && cx <= Size * 40 + 120 && Size * 40 - 40 <= cy && cy <= Size * 40) {
                pressed = true;
                return moveRight;
            }
        }
    }
    if(event.type == sf::Event::KeyPressed && !pressed) {
        if (event.key.code == SaveAndLoad[0]) {
            return save1;
        }
        if (event.key.code == SaveAndLoad[2]) {
            return save;
        }
        if (event.key.code == SaveAndLoad[1]) {
            return load1;
        }
        if (event.key.code == SaveAndLoad[3]) {
            return load;
        }
        if(event.key.code == direction[0] && !pressed){
            pressed = true;
            return moveLeft;
        }
        if(event.key.code == direction[1] && !pressed){
            pressed = true;
            return moveUp;
        }
        if(event.key.code == direction[2] && !pressed){
            pressed = true;
            return moveRight;
        }
        if(event.key.code == direction[3] && !pressed){
            pressed = true;
            return moveDown;
        }
    }
    if((event.type == sf::Event::KeyReleased || event.type == sf::Event::MouseButtonReleased) && pressed){
        pressed = false;
        return objectAction;
    }
    return nothing;
}

Commander::Commander(sf::Keyboard::Key b1, sf::Keyboard::Key b2, sf::Keyboard::Key b3, sf::Keyboard::Key b4) {
    if(b1 == b2 || b1 == b3 || b1 == b4 || b2 == b3 || b2 == b4 || b3 == b4){
        std::cout << "Several identical buttons were introduced. Use usual buttons: WASD\n";
    }
    else {
        direction[0] = b1;
        direction[1] = b2;
        direction[2] = b3;
        direction[3] = b4;
    }
}
