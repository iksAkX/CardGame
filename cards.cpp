
#include "cards.h"

bool Artifact::areAllDestroyed = false;
sf::Sprite Cards::cursor;
int Cards::CardsInHand = 0;
int Cards::CardsOnBattlefield = 0;

Character Cards::opponent;
Character Cards::caster;

void Cards::setCharacters(Character &caster, Character &opponent){

Cards::caster = caster;
Cards::opponent = opponent;
}

void Cards::discard(){

if (this->where=='h')
{
    this->where='g';
    Cards::CardsInHand--;
}
}

void Cards::setCursor(sf::Sprite &cursorReference){

Cards::cursor = cursorReference;
}

bool Cards::getPriority(){

return this->priority;

}

int Cards::getId(){

return this->id;
}

void Artifact::play(){

if (Cards::caster.getActiveMana() <= this-> manaCost && this->where == 'h')
{


Cards::caster.spendActiveMana(this->manaCost);
this->where='b';
Cards::CardsOnBattlefield++;
Cards::CardsInHand--;
this->cardSprite.setPosition(Cards::CardsOnBattlefield*100, 450);
}

else std::cout << "You don't have enough mana OR this card isn't in your hand so you cannot play card with name: " << this->name << std::endl;

}

sf::Sprite Cards::getSprite(){

return this->cardSprite;

}


void Artifact::refreshArtifacts(){ // use at the end of each turn

Artifact::areAllDestroyed=false;
}


void Cards::setPosition(float x, float y){

this->cardSprite.setPosition(x, y);

}

void Cards::changePosition(float x, float y){

this->cardSprite.move(x, y);

}



void Spell::giveEffect(){

        switch (this->id){

case 11:
    Artifact::areAllDestroyed=true;
    break;


case 12:
    Cards::caster.loseHealth(15);
    Cards::caster.receiveArmor(25);
    break;

case 13:
 Cards::opponent.receiveArmor(10);
 Cards::caster.receiveArmor(10);
 if(Cards::caster.getHealth() < 10)Cards::caster.heal();
    break;


case 14:
    Cards::opponent.loseHealth(8);
    break;

case 15:

//draw 3 cards
Cards::caster.heal();
Cards::caster.receiveArmor(30);
Cards::opponent.loseHealth(3);

    break;


}
}

bool Artifact::draw(){


if(this->where == 'd' && CardsInHand <= 5)
{
    Cards::CardsInHand++;
    this->cardSprite.setPosition(Cards::CardsInHand*210, 530);

    this->where='h';
    std::cout << "Artifact number " << this->id << " was tried to draw." << std::endl;
    return true;
}


else return false;

}

bool Weapon::draw(){

if(this->where == 'd' && CardsInHand <= 5)
{
    Cards::CardsInHand++;
    this->cardSprite.setPosition(Cards::CardsInHand*210, 530);

    this->where='h';
     std::cout << "Weapon number " << this->id << " was tried to draw." << std::endl;
    return true;
}

else return false;

}

bool Skill::draw(){

if(this->where == 'd' && CardsInHand <= 5)
{
    Cards::CardsInHand++;
    this->cardSprite.setPosition(Cards::CardsInHand*210, 530);

    this->where='h';
     std::cout << "Skill number " << this->id << " was tried to draw." << std::endl;
    return true;
}

else return false;

}

bool Spell::draw(){

if(this->where == 'd' && CardsInHand <= 5)
{
        Cards::CardsInHand++;
    this->cardSprite.setPosition(Cards::CardsInHand*210, 530);

    this->where='h';
     std::cout << "Spell number " << this->id << " was tried to draw." <<std::endl;
    return true;
}

else return false;

}

 void Artifact::giveEffect(){

switch(this->id){

case 1:
   Cards::caster.heal();
    break;


case 2:
    Cards::opponent.loseHealth(2);
    break;


case 3:
    Cards::opponent.gainHealth(3);
    Cards::caster.gainHealth(3);
    break;


case 4:
    Cards::opponent.loseHealth(20);
    break;


case 5:
  Cards::caster.receiveArmor(16);
    break;


}



}


void Artifact::decreaseTimer(){

    this->actualTimer--;

if(this->actualTimer == 0)
{
    giveEffect();
    this->actualTimer = this->maxTimer;
}

}


void Artifact::loseHealth(int amount){

this->actualHealth-=amount;
if (this->actualHealth <= 0)this->where='g';

}


void Spell::play() {


if (Cards::caster.getActiveMana() <= this-> manaCost && this->where == 'h')
{
Cards::caster.spendActiveMana(this->manaCost);
this->where='g';
    Cards::CardsInHand--;
this->cardSprite.setPosition(-1000, -1000);
}

else std::cout << "You don't have enough mana OR this card isn't in your hand so you cannot play card with name: " << this->name << std::endl;


}



void Weapon::play() {

if (Cards::caster.getActiveMana() <= this-> manaCost && this->where == 'h')
{
Cards::caster.spendActiveMana(this->manaCost);
this->where='b';
Cards::CardsInHand--;
Cards::CardsOnBattlefield++;
this->cardSprite.setPosition(Cards::CardsOnBattlefield*100, 500);
}

else std::cout << "You don't have enough mana OR this card isn't in your hand so you cannot play card with name: " << this->name << std::endl;


}

void Skill::play(){

if (Cards::caster.getActiveMana() <= this-> manaCost && this->where == 'h')
{
Cards::caster.spendActiveMana(this->manaCost);
this->where='g';
Cards::CardsInHand--;
this->cardSprite.setPosition(-1000, -1000);
}

else std::cout << "You don't have enough mana OR this card isn't in your hand so you cannot play card with name: " << this->name << std::endl;


}


void Weapon::giveEffect(){


}

void Skill::giveEffect(){

}

Weapon::Weapon(){

this->cardSprite.setPosition(-1000,-1000);
this->cardTexture.setSmooth(true);
}

void Weapon::setThis(int id, std::string name, int manaCost, int rarity, char where, std::string whereIsTexture, int attack, int durability){

cardTexture.loadFromFile(whereIsTexture);
    cardSprite.setTexture(cardTexture);

    this->attack=attack;
    this->durability=durability;

    this->id = id;
    this->rarity = rarity;
    this->name = name;
    this->where = where;
    this->manaCost = manaCost;
    this->cardSprite.setPosition(-1000,-1000);
}


Skill::Skill(){

this->cardSprite.setPosition(-1000,-1000);
this->cardTexture.setSmooth(true);

}

void Skill::setThis(int id, std::string name, int manaCost, int rarity, char where, std::string whereIsTexture){

this->cardTexture.loadFromFile(whereIsTexture);
this->cardSprite.setTexture(this->cardTexture);


    this->id = id;
    this->rarity = rarity;
    this->name = name;
    this->where = where;
    this->manaCost = manaCost;
    this->cardSprite.setPosition(-1000,-1000);
}


Spell::Spell(){

this->cardSprite.setPosition(-1000,-1000);
this->cardTexture.setSmooth(true);
}

void Spell::setThis(int id, std::string name, int manaCost, int rarity, char where, std::string whereIsTexture){


this->cardTexture.loadFromFile(whereIsTexture);
this->cardSprite.setTexture(this->cardTexture);


    this->id = id;
    this->rarity = rarity;
    this->name = name;
    this->where = where;
    this->manaCost = manaCost;
    this->cardSprite.setPosition(-1000,-1000);
}


Artifact::Artifact(){

this->cardSprite.setPosition(-1000,-1000);
this->cardTexture.setSmooth(true);

}

void Artifact::setThis(int id, std::string name, int manaCost, int rarity, char where, std::string whereIsTexture, int maxTimer, int maxHealth){


this->cardTexture.loadFromFile(whereIsTexture);
this->cardSprite.setTexture(this->cardTexture);

this->maxTimer = maxTimer;
this->maxHealth = maxHealth;

this->id = id;
this->rarity = rarity;
this->name = name;
this->where = where;
this->manaCost = manaCost;
this->cardSprite.setPosition(-1000,-1000);
}

void Artifact::getDestroyed(){

this->where='g';
this->cardSprite.setPosition(-1000,-1000);
}


void Weapon::getDestroyed(){

this->where='g';
this->cardSprite.setPosition(-1000,-1000);
}


void Artifact::checkStatus(){


if(Artifact::areAllDestroyed)getDestroyed();


{// It controls zooming and unzooming cards.
    this->cardSprite.setScale(0.5, 0.5); // older:     this->cardSprite.setScale(1, 1);

sf::FloatRect boundingBoxCursor = Cards::cursor.getGlobalBounds();
sf::FloatRect cardBoundingBox = this->cardSprite.getGlobalBounds();




if (boundingBoxCursor.intersects(cardBoundingBox) && this->cardSprite.getScale().x < 0.9)
{
        this->priority = true;
       this->cardSprite.setScale(1, 1);
}
if (!boundingBoxCursor.intersects(cardBoundingBox))this->priority=false;

}


if (this->priority && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
    play();

    }

}

void Weapon::checkStatus(){

if (this->durability <= 0)getDestroyed();
{// It zooms and unzooms cards.
      this->cardSprite.setScale(0.5, 0.5);

sf::FloatRect boundingBoxCursor = Cards::cursor.getGlobalBounds();
sf::FloatRect cardBoundingBox = this->cardSprite.getGlobalBounds();


if (boundingBoxCursor.intersects(cardBoundingBox) && this->cardSprite.getScale().x < 0.9){

    this->cardSprite.setScale(1, 1);
        this->priority = true;
}
if (!boundingBoxCursor.intersects(cardBoundingBox))this->priority=false;
}


if (this->priority && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
    play();

    }

}





void Cards::checkStatus(){



{// It zooms and unzooms cards.
      this->cardSprite.setScale(0.5, 0.5);

sf::FloatRect boundingBoxCursor = Cards::cursor.getGlobalBounds();
sf::FloatRect cardBoundingBox = this->cardSprite.getGlobalBounds();


if (boundingBoxCursor.intersects(cardBoundingBox) && this->cardSprite.getScale().x < 0.9)
{
    this->cardSprite.setScale(1, 1);
    this->priority = true;
}
if (!boundingBoxCursor.intersects(cardBoundingBox)){


        this->priority=false;
}
}



if (this->priority && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
    play();

    }

}

