#include "SaveAndLoad.h"


void SaveAndLoad::Save(HeroAction *heroAct, ObjectAction *objAct, Command command) {
    std::string file;
    if(command == save1){
        file = "save1";
    }
    else{
        std::cout << "Please, enter the name of save:" << std::endl;
        std::cin >> file;
        if(file == "save1"){
            std::cout << "This name don't available" << std::endl;
            return;
        }
    }

    std::ofstream save_file;
    save_file.open("../save/"+file + ".txt");

    save_file << objAct->GetData() + heroAct->GetData();

    save_file.close();
}

void SaveAndLoad::Load(HeroAction *heroAct, ObjectAction *objAct, Command command) {
    std::string file;
    if(command == load1){
        file = "save1";
    }
    else{
        std::cout << "Please, enter the name to load:" << std::endl;
        std::cin >> file;
    }

    std::ifstream save_file;
    save_file.open("../save/"+file + ".txt", std::ios::in);
    if (save_file.fail())
    {
        throw LoadError("This save does not exist");
    }

    //new field
    Field* new_field = new Field();
    int type;
    for(int i = 0; i < Size; i++){
        for(int j = 0; j  < Size; j ++){
            if(save_file >> type && (type == Wall || type == Floor || type == Enter || type == Exit)){
                new_field->GetCells()[i][j].SetType((CellTypes)type);
            }
            else{
                delete new_field;
                throw LoadError(cellEr, typeEr);
            }
        }
    }

    //new thing
    Thing** new_thing;
    int new_THING;
    int x, y;
    if(save_file >> new_THING && new_THING >= 0 && new_THING <= (int)(Size*Size*4/100)){
        new_thing = new Thing*[new_THING];
        for(int i = 0; i < new_THING; i++){
            if(save_file >> type && (type == coin || type == axe || type == candy)){
                if(type == coin){
                    new_thing[i] = new Coin();
                }
                else if(type == axe){
                    new_thing[i] = new Axe();
                }
                else if(type == candy){
                    new_thing[i] = new Candy();
                }
                if(save_file >> x >> y && ((x > 0 && x <= Size - 2 && y > 0 && y <= Size - 2) || (x == -1 && y == -1))){
                    new_thing[i]->SetCoord(x, y);
                    if(x == -1 && y == -1){
                        new_thing[i]->GetData(); //is_available = false;
                    }
                    else if(new_field->GetCells()[x][y].GetObjectType()!=empty){
                        delete new_field;
                        for(int j = 0; j <= i; j++){
                            delete new_thing[j];
                        }
                        delete [] new_thing;
                        throw LoadError(thingEr, posEr);
                    }
                    else new_field->GetCells()[x][y].SetObject(new_thing[i]);
                }
                else{
                    delete new_field;
                    for(int j = 0; j <= i; j++){
                        delete new_thing[j];
                    }
                    delete [] new_thing;
                    throw LoadError(thingEr, posEr);
                }
            }
            else{
                delete new_field;
                for(int j = 0; j < i; j++){
                    delete new_thing[j];
                }
                delete [] new_thing;
                throw LoadError(thingEr, typeEr);
            }
        }
    }
    else{
        delete new_field;
        throw LoadError(thingEr, numbEr);
    }
    //new enemy
    Unit** new_enemy;
    int new_ENEMY;
    int health;
    if(save_file >> new_ENEMY && new_ENEMY >= 0 && new_ENEMY <= (int)(Size*Size*4/100)){
        new_enemy = new Unit*[new_ENEMY];
        for(int i = 0; i < new_ENEMY; i++){
            if(save_file >> type && (type == eye || type == ent || type == spider)){
                if(type == eye){
                    new_enemy[i] = new Eye();
                }
                else if(type == ent){
                    new_enemy[i] = new Ent();
                }
                else if(type == spider){
                    new_enemy[i] = new Spider();
                }
                if(save_file >> x >> y && ((x > 0 && x <= Size - 2 && y > 0 && y <= Size - 2) || (x == -1 && y == -1))){
                    new_enemy[i]->SetCoord(x, y);
                    if(x == -1 && y == -1){
                        new_enemy[i]->SetHealth(-5); //is_alive = false;
                    }
                    else if(new_field->GetCells()[x][y].GetObjectType()!=empty){
                        delete new_field;
                        for(int j = 0; j <= i; j++){
                            delete new_enemy[j];
                        }
                        delete [] new_enemy;
                        for(int j = 0; j < new_THING; j++){
                            delete new_thing[j];
                        }
                        delete [] new_thing;
                        throw LoadError(enemyEr, posEr);
                    }
                    else new_field->GetCells()[x][y].SetObject(new_enemy[i]);
                }
                else{
                    delete new_field;
                    for(int j = 0; j <= i; j++){
                        delete new_enemy[j];
                    }
                    delete [] new_enemy;
                    for(int j = 0; j < new_THING; j++){
                        delete new_thing[j];
                    }
                    delete [] new_thing;
                    throw LoadError(enemyEr, posEr);
                }
                if(save_file >> health){
                    if(new_enemy[i]->IsAlive()){
                        new_enemy[i]->SetHealth(health);
                        if(!new_enemy[i]->IsAlive()){
                            new_field->GetCells()[x][y].SetObject(nullptr);
                        }
                    }
                }
                else{
                    delete new_field;
                    for(int j = 0; j <= i; j++){
                        delete new_enemy[j];
                    }
                    delete [] new_enemy;
                    for(int j = 0; j < new_THING; j++){
                        delete new_thing[j];
                    }
                    delete [] new_thing;
                    throw LoadError(enemyEr, hpEr);
                }
            }
            else{
                delete new_field;
                for(int j = 0; j < i; j++){
                    delete new_enemy[j];
                }
                delete [] new_enemy;
                for(int j = 0; j < new_THING; j++){
                    delete new_thing[j];
                }
                delete [] new_thing;
                throw LoadError(enemyEr, typeEr);
            }
        }
    }
    else{
        delete new_field;
        for(int i = 0; i < new_THING; i++){
            delete new_thing[i];
        }
        delete [] new_thing;
        throw LoadError(enemyEr, numbEr);
    }

    Hero* new_gamer;
    int force;
    int max_health;
    int coins;
    if(save_file >> type && type == hero){
        new_gamer = new Hero();
        if(save_file >> x >> y && ((x > 0 && x <= Size - 2 && y > 0 && y <= Size - 2) || (x == -1 && y == -1)) || (x == Size -1 && y == Size -2)){
            new_gamer->SetCoord(x, y);
            if(x == -1 && y == -1){
                new_gamer->SetHealth(-5); //is_alive = false;
            }
            else if(new_field->GetCells()[x][y].GetObjectType()!=empty){
                delete new_field;
                for(int j = 0; j < new_ENEMY; j++){
                    delete new_enemy[j];
                }
                delete [] new_enemy;
                for(int j = 0; j < new_THING; j++){
                    delete new_thing[j];
                }
                delete [] new_thing;
                delete new_gamer;
                throw LoadError(heroEr, posEr);
            }
            else new_field->GetCells()[x][y].SetObject(new_gamer);
        }
        else{
            delete new_field;
            for(int j = 0; j < new_ENEMY; j++){
                delete new_enemy[j];
            }
            delete [] new_enemy;
            for(int j = 0; j < new_THING; j++){
                delete new_thing[j];
            }
            delete [] new_thing;
            delete new_gamer;
            throw LoadError(heroEr, posEr);
        }

        if(save_file >> health && health > 0){
            if(new_gamer->IsAlive()){
                new_gamer->SetHealth(health);
            }
        }
        else{
            delete new_field;
            for(int i = 0; i < new_THING; i++){
                delete new_thing[i];
            }
            for(int i = 0; i < new_ENEMY; i++){
                delete new_enemy[i];
            }
            delete [] new_enemy;
            delete new_gamer;
            throw LoadError(heroEr, hpEr);
        }

        if(save_file >> force && force > 0){
            new_gamer->SetForce(force);
        }
        else{
            delete new_field;
            for(int i = 0; i < new_THING; i++){
                delete new_thing[i];
            }
            for(int i = 0; i < new_ENEMY; i++){
                delete new_enemy[i];
            }
            delete [] new_enemy;
            delete new_gamer;
            throw LoadError(heroEr, forceEr);
        }

        if(save_file >> max_health && max_health >= health){
            new_gamer->SetMaxHealth(max_health);
        }
        else{
            delete new_field;
            for(int i = 0; i < new_THING; i++){
                delete new_thing[i];
            }
            for(int i = 0; i < new_ENEMY; i++){
                delete new_enemy[i];
            }
            delete [] new_enemy;
            delete new_gamer;
            throw LoadError(heroEr, mhpEr);
        }

        if(save_file >> coins && coins >= 0){
            new_gamer->SetCoins(coins);
        }
        else{
            delete new_field;
            for(int i = 0; i < new_THING; i++){
                delete new_thing[i];
            }
            for(int i = 0; i < new_ENEMY; i++){
                delete new_enemy[i];
            }
            delete [] new_enemy;
            delete new_gamer;
            throw LoadError(heroEr, coinEr);
        }
    }
    else{
        delete new_field;
        for(int i = 0; i < new_THING; i++){
            delete new_thing[i];
        }
        for(int i = 0; i < new_ENEMY; i++){
            delete new_enemy[i];
        }
        delete [] new_enemy;
        throw LoadError(heroEr, typeEr);
    }

    objAct->GetStats(new_enemy, new_thing, new_ENEMY, new_THING, new_field);
    heroAct->GetStats(new_gamer, new_field);

    save_file.close();
}
