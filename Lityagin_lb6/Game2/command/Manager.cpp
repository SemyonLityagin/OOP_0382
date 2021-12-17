#include "Manager.h"

Manager::Manager(ObjectAction* objAct, HeroAction* heroAct) {
    this->objAct = objAct;
    this->heroAct = heroAct;
}

void Manager::DoIteration(Command command) {
    if(window == nullptr){
        throw std::invalid_argument("Please, firstly set sf::RenderWindow");
    }
    switch(command){
        case objectAction:{
            objAct->CheckObject();
            objAct->MoveEnemy();
            break;
        }
        case moveRight:{
            heroAct->MoveHeroRight();
            break;
        }
        case moveLeft:{
            heroAct->MoveHeroLeft();
            break;
        }
        case moveUp:{
            heroAct->MoveHeroUp();
            break;
        }
        case moveDown:{
            heroAct->MoveHeroDown();
            break;
        }
        case close:{
            std::cout << "game close!";
            window->close();
            break;
        }
        case death:{
            if(heroAct->CheckDeath()){
                std::cout << "hero dead!";
                window->close();
            }
            break;
        }
        case win:{
            if(heroAct->CheckWin()){
                std::cout << "hero win!";
                window->close();
            }
            break;
        }
        case save:{
            SaveAndLoad::Save(heroAct, objAct, command);
            break;
        }
        case load:{
            try{
                SaveAndLoad::Load(heroAct, objAct, command);
            }
            catch(LoadError &exception){
                std::cerr << "LoadError: " << exception.getError() << std::endl;
            }
            break;
        }
        case save1:{
            SaveAndLoad::Save(heroAct, objAct, command);
            break;
        }
        case load1:{
            try{
                SaveAndLoad::Load(heroAct, objAct, command);
            }
            catch(LoadError &exception){
                std::cerr << "LoadError: " << exception.getError() << std::endl;
            }
            break;
        }
    }
}

void Manager::SetWindow(sf::RenderWindow *window) {
    this->window = window;
}

Manager::~Manager() {
    delete objAct;
    delete heroAct;
}

