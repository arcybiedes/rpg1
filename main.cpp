#include <iostream>
#include <random>

class Character{
public:
    int health;
    std::string* moves = new std::string [7];
    bool is_drunken = false;
    bool is_blinded = false;
    bool is_blocked = false;
    int strength;
    std::string orange = "Nie dla psa, dla orka to!";

    Character(std::string* moves, bool is_drunken, bool is_blinded, int strength, int health){
        this->moves = moves;
        this->is_drunken = is_drunken;
        this->is_blinded = is_blinded;
        this->health = health;
        this->strength = strength;
    }
    void attack(Character& enemy){
        enemy.health -= this->strength;
    }
    void dodge(Character& enemy){
        this->health -= enemy.strength/2;
    };
    void retreat(Character& enemy){
        if (this->is_drunken == true) {
            enemy.health -=enemy.strength*2.5;
        } else{
            this->health -=enemy.strength*2;
        }
    }
    void block(){
        this->is_blocked =true;
    }
};
class Enemy : public Character {
protected:
    bool is_sensitive = false;
    int smash;
    int bash;
    int dash;
    int slash;
    using Character::Character;
public:
    int get_smash(){
        return this->smash;
    };
    int get_bash(){
        return this->bash;
    };
    int get_dash(){
        return this->dash;
    };
    int get_slash(){
        return this->slash;
    };
    void set_smash(int smash){
        //if (smash > 100){
            //std::cout << "Nie mieszaj mi w wartościach, chuju!" << std::endl;
        //}
        //else {
            //std::cout << "Ciekawe, napisz do mnie." << std::endl;
            this->smash = smash;
        //};
    };
    void set_bash(int bash){
        this->bash = bash;
    };
    void set_dash(int dash){
        this->dash = dash;
    };
    void set_slash(int slash){
        this-> slash = slash;
    };
};


int main() {
    std::string* moves = new std::string [7]{
           "attack", "dodge", "retreat", "block", "kamehamema"
    };
    Character character(moves, false, false, 3, 10);
    std::string* enemy_moves = new std::string [7] {
        "smash", "bash", "dash", "slash", "flash", "orange"
    };
    Enemy enemy(enemy_moves, false, false, 4, 15);
    //enemy.set_smash(enemy.strength - 2);
    std::cout << enemy.get_smash() << std::endl;
    enemy.set_bash(enemy.strength - 1);
    enemy.set_dash(character.strength - character.strength);
    enemy.set_slash(enemy.strength + 2);
    std::string* w_moves = new std::string [7] {
        "magic_attack", "belly_dodge", "ungraceful_retreat", "shoulder_block", "mighty_kamehamema"
    };
    Character warkoholik(w_moves, false, false, character.strength*2, character.health);
    std::string move;
    srand(time(NULL));
    std::cout << "You have been attacked! What's your move?" << std::endl;
    for (int start = 0; start <= 4; start++) {
        std::cout << character.moves[start] << std::endl;

    }
    while (character.health > 0 && enemy.health > 0) {
        std::cin >> move;
        int dice = rand() % 6 + 1;
        if (character.is_blinded == false) {
            if (move == "attack") {
                character.attack(enemy);
            } else if (move == "dodge") {
                character.dodge(enemy);
            } else if (move == "retreat") {
                character.retreat(enemy);
            } else if (move == "block") {
               character.block();
            } else if (move == "kamehamema") {
                std::cout << "It's super uneffective!" << std::endl;
            } else if (move == "harnold") {
                std::cout << "Magiczny napój has been drunk! Your powers are multiplied!" << std::endl;
                character.is_drunken = true;
                for (int start = 0; start <= 4; start++) {
                    std::cout << warkoholik.moves[start] << std::endl;
                }
                break;
            } else {
                std::cout << "What are you doing?" << std::endl;
            }
        } else {
            std::cout << "You have been blinded! You miss your turn!" << std::endl;
            character.is_blinded = false;
        }
        if (dice == 1) {
            std::cout << "Enemy smashed your butt off!" << std::endl;
            if (character.is_blocked == false){
                character.health = character.health - enemy.get_smash();
            }
        } else if (dice == 2) {
            std::cout << "Enemy bashed into your body!" << std::endl;
            if (character.is_blocked == false) {
                character.health = character.health - enemy.get_bash();
            }
        } else if (dice == 3) {
            std::cout << "Enemy is coming for you. Watch out!" << std::endl;
            if (character.is_blocked == false)
            {
                character.health = character.health;
            }
        } else if (dice == 4) {
            std::cout << "Enemy unsheathes his sword on you and slashes vertically!" << std::endl;
            if (character.is_blocked == false) {
                character.health = character.health - enemy.get_slash();
            }
        } else if (dice == 5) {
            std::cout << "Enemy's eyes started to glow radiantly onto you, making you temporarily impaired!"
                      << std::endl;
            if (character.is_blocked == false) {
                character.is_blinded = true;
            }
        } else if (dice == 6) {
            std::cout << "Enemy is offering you the orange. Will you accept it?" << std::endl;
            std::cout << enemy.orange << std::endl;
        }
        std::cout << "Player's Health" << character.health << "\n" << "Enemy's Health" << enemy.health << "\n"
                  << std::endl;
    }
    while (warkoholik.health > 0 && enemy.health > 0) {
        std::cin >> move;
        int dice = rand() % 6 + 1;
        if (move == "magic_attack") {
            enemy.health = enemy.health - warkoholik.strength;
        } else if (move == "belly_dodge") {
            enemy.health = enemy.health - enemy.strength;
        } else if (move == "ungraceful_retreat") {
            enemy.health = enemy.health - enemy.strength * 3;
        } else if (move == "shoulder_block") {

        } else if (move == "mighty_kamehamema") {
            std::cout << "It's super effective!" << std::endl;
            enemy.health = 0;

        } else {
            std::cout << "What are you doing?" << std::endl;
        }
        if (dice == 1) {
            std::cout << "Enemy smashed your drunken-ass! What you gonna do?" << std::endl;
            if (character.is_blocked == false) {
                warkoholik.health = warkoholik.health - enemy.get_smash();
            }
        } else if (dice == 2) {
            std::cout << "This clunker has bashed onto ya! Strike back at 'im!" << std::endl;
            if (character.is_blocked == false) {
                warkoholik.health = warkoholik.health - enemy.get_bash();
            }
        } else if (dice == 3) {
            std::cout << "Enemy is scared of your mighty! Charge proudly!" << std::endl;
            if (character.is_blocked == false) {
                warkoholik.health = warkoholik.health;
            }
        } else if (dice == 4) {
            std::cout << "Enemy dares to use his cocksized knife on ya! Show 'im your weapon!" << std::endl;
            if (character.is_blocked == false) {
                warkoholik.health = warkoholik.health - enemy.get_slash();
            }
        } else if (dice == 5) {
            std::cout << "Flashbang! Wait... it's not that game.." << std::endl;
            if (character.is_blocked == false) {
                warkoholik.is_blinded = true;
            }
        } else if (dice == 6) {
            std::cout << "Spit on his sorry orange! Show 'im the cocoNUTS you have on you!" << std::endl;
            std::cout << enemy.orange << std::endl;
        }
        std::cout << "Player's Health" << warkoholik.health << "\n" << "Enemy's Health" << enemy.health << "\n"
                  << std::endl;
    }
};