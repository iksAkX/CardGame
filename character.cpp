#include "character.h"
#include <sstream>

 bool Character::isEnemyTurn = false; // you start the game as first

Character::Character(){
}


Character::~Character(){
}


void Character::setCharacter(std::string name, int health, int armor, sf::Text characterName, sf::Texture characterTexture, sf::Sprite characterSprite, int activeMana, int maxMana){
 this -> maxHealth = health;
 this -> initialArmor = armor;

 this -> activeMana = activeMana;
 this -> maxMana = maxMana;
 this -> name = name;
 this -> health = health;
 this -> armor = armor;
 this -> characterName = characterName;
 this -> characterTexture = characterTexture;
 this -> characterSprite = characterSprite;

 characterSprite.setTexture(characterTexture);
    }


int Character::getArmor(){

 return this -> armor;
}


int Character::getHealth(){

 return this -> health;
}


std::string Character::getCharacterNameAsString(){
 return this -> name;
}


sf::Texture Character::getCharacterTexture(){
 return this -> characterTexture;
}


sf::Sprite Character::getCharacterSprite(){
 return this -> characterSprite;
}


sf::Text Character::getCharacterNameAsText(){
 return this -> characterName;
}


void Character::loseHealth(int damage){

    if (this->armor == 0) this->health-=damage; // no armor
    else if (this->armor == damage)this->armor=0;
    else if (this->armor > damage)this->armor-=damage;
    else if (this->armor < damage){
     damage-= this->armor;
     this->health -= damage;
    }

}


void Character::setName(std::string name){

 this->name=name;
 this->characterName.setString(name);
}


void Character::setTexture(std::string imageLocation){

 this->characterTexture.loadFromFile(imageLocation);
}

void Character::restoreMana(){

 this->activeMana = this->maxMana;
}


void Character::heal(){

 this->health = this->maxHealth;
}


void Character::gainHealth(int amount){

 this->health+=amount;
}


void Character::setMaxHealth(int value){

this->maxHealth=value;
}


void Character::decreaseMaxHealth(int amount){

 this->maxHealth-=amount;
}

void Character::increaseMaxHealth(int amount){

 this->maxHealth-=amount;
}


void Character::receiveArmor(int amount){

this->armor+=amount;
}


bool Character::isDead(){

    if (this->health <= 0)return true;
    else return false;
}


void Character::gainActiveMana(int amount){

 this->activeMana+=amount;
}


void Character::gainMaxMana(int amount){

 this->maxMana+=amount;
}


void Character::spendActiveMana(int amount){

 this->activeMana-=amount;
}


int Character::getActiveMana(){

 return this->activeMana;
}


int Character::getMaxMana(){

 return this->maxMana;
}


std::string Character::getName(){

 return this->name;
}


std::string Character::getHealthAsString(){

std::ostringstream ss;
ss << this->health;
std::string str = ss.str();

return str;
}


void Character::showStatus(){

std::cout << "Player: " << getName() << "\nActive/Max mana: " << getActiveMana() << " / " << getMaxMana() << "\n ================ \n";
}
