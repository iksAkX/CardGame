
#include "character.h"

Character::Character(){

}

Character::~Character(){

}

  void Character::setCharacter(std::string name, int health, int armor, sf::Text characterName, sf::Texture characterTexture, sf::Sprite characterSprite, int activeMana, int maxMana){
this -> initialHealth = health;
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



int Character::getHealth()
{
    return this -> health;
}

std::string Character::getCharacterNameAsString()
{
    return this -> name;
}

sf::Texture Character::getCharacterTexture()
{
    return characterTexture;
}

sf::Sprite Character::getCharacterSprite(){
return this -> characterSprite;
}

sf::Text Character::getCharacterNameAsText()
{
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


void Character::changeName(std::string name){

this->name=name;
this->characterName.setString(name);

}


void Character::changeTexture(std::string imageLocation){

this-> characterTexture.loadFromFile(imageLocation);

}


void Character::heal(){

this->health = this->initialHealth;


}


void Character::gainHealth(int amount){

this->health+=amount;

}


void Character::setInitalHealth(int value){

this->initialHealth=value;
}


void Character::decreaseInitialHealth(int amount){

 this->initialHealth-=amount;
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


