#include "cards.h"

bool Artifact::areAllDestroyed = false;
sf::Sprite Cards::cursor;

int Cards::CardsInHand = 0;
int Cards::CardsInHandAI = 0;
int Cards::CardsOnBattlefield = 0;
int Cards::CardsOnBattlefieldAI = 0;

int Cards::maxNumberCardsInHand = 6;

Character Cards::opponent;
Character Cards::caster;


char Cards::getWhere(){

    return this->where;
}

void Cards::setCharacters(Character &caster, Character &opponent){

    Cards::caster = caster;
    Cards::opponent = opponent;
}

int Cards::getManaCost(){

    return this->manaCost;
}


void Cards::discard(){

    if(this->where=='h'){
 this->where='g';
    if(Cards::caster.getName() == "You")Cards::CardsInHand--;
    else Cards::CardsInHandAI--;
 this->cardSprite.setPosition(-1000,-1000);

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

    if(Cards::caster.getName() == "You"){
        if(Cards::caster.getActiveMana() >= this->manaCost && this->where == 'h'){
         Cards::caster.spendActiveMana(this->manaCost);
         Cards::CardsInHand--;
         Cards::CardsOnBattlefield++;
         this->cardSprite.setPosition(Cards::CardsOnBattlefield*210, 530);
         this->where='b';
         std::cout<<"You have played card is called " << this->name << "\n Active mana: " << Cards::caster.getActiveMana() << std::endl;
     }
     std::cout<<"You couldn't card is called " << this->name << "\n Active mana: " << Cards::caster.getActiveMana()<< std::endl;
    }

    else {
        if(Cards::caster.getActiveMana() >= this->manaCost && this->where == 'h'){
         Cards::caster.spendActiveMana(this->manaCost);
         Cards::CardsInHandAI--;
         Cards::CardsOnBattlefieldAI++;
         this->cardSprite.setPosition(Cards::CardsOnBattlefieldAI*210, 400);
         this->where='b';
         std::cout<<"Bot has played card is called " << this->name << "\n Active mana: " << Cards::caster.getActiveMana() << std::endl;
        }
        std::cout<<"Bot couldn't play card is called " << this->name << "\n Active mana: " << Cards::caster.getActiveMana()<< std::endl;
    }
}

sf::Sprite Cards::getSprite(){

    return this->cardSprite;
}


void Artifact::refreshArtifacts(){

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

 this->cardSprite.setOrigin(this->cardTexture.getSize().x/2, this->cardTexture.getSize().y/2);
 this->cardSprite.setScale(0.5, 0.5);

    if (Cards::caster.getName() == "You"){
        if(this->where == 'd' && CardsInHand < Cards::maxNumberCardsInHand){
         Cards::CardsInHand++;
         this->cardSprite.setPosition(Cards::CardsInHand*210, 830);
         this->where='h';
         return true;
        }
         std::cout << "You have too many cards in hand! You can't draw more.\n";
     return false;
    }

    else {
        if(this->where == 'd' && CardsInHandAI < Cards::maxNumberCardsInHand){
         Cards::CardsInHandAI++;
         this->cardSprite.setPosition(CardsInHandAI*210, 180);
         this->where='h';
         return true;
        }
         std::cout << "Bot has too many cards in hand! He can't draw more.\n";
     return false;
    }

}




bool Weapon::draw(){

 this->cardSprite.setScale(0.5, 0.5);
 this->cardSprite.setOrigin(this->cardTexture.getSize().x/2, this->cardTexture.getSize().y/2);

     if (Cards::caster.getName() == "You"){
        if(this->where == 'd' && CardsInHand < Cards::maxNumberCardsInHand){
         Cards::CardsInHand++;
         this->cardSprite.setPosition(Cards::CardsInHand*210, 830);
         this->where='h';
         return true;
        }
         std::cout << "You have too many cards in hand! You can't draw more.\n";
     return false;
    }

    else {
        if(this->where == 'd' && CardsInHandAI < Cards::maxNumberCardsInHand){
         Cards::CardsInHandAI++;
         this->cardSprite.setPosition(CardsInHandAI*210, 180);
         this->where='h';
         return true;
        }
         std::cout << "Bot has too many cards in hand! He can't draw more.\n";
     return false;
    }
}


bool Skill::draw(){

 this->cardSprite.setScale(0.5, 0.5);
 this->cardSprite.setOrigin(this->cardTexture.getSize().x/2, this->cardTexture.getSize().y/2);

    if (Cards::caster.getName() == "You"){
        if(this->where == 'd' && CardsInHand < Cards::maxNumberCardsInHand){
         Cards::CardsInHand++;
         this->cardSprite.setPosition(Cards::CardsInHand*210, 830);
         this->where='h';
         return true;
        }
         std::cout << "You have too many cards in hand! You can't draw more.\n";
     return false;
    }

    else {
        if(this->where == 'd' && CardsInHandAI < Cards::maxNumberCardsInHand){
         Cards::CardsInHandAI++;
         this->cardSprite.setPosition(CardsInHandAI*210, 180);
         this->where='h';
         return true;
        }
         std::cout << "Bot has too many cards in hand! He can't draw more.\n";
     return false;
    }
}


bool Spell::draw(){

 this->cardSprite.setScale(0.5, 0.5);
 this->cardSprite.setOrigin(this->cardTexture.getSize().x/2, this->cardTexture.getSize().y/2);

    if (Cards::caster.getName() == "You"){
        if(this->where == 'd' && CardsInHand < Cards::maxNumberCardsInHand){
         Cards::CardsInHand++;
         this->cardSprite.setPosition(Cards::CardsInHand*210, 830);
         this->where='h';
         return true;
        }
         std::cout << "You have too many cards in hand! You can't draw more.\n";
     return false;
    }

    else {
        if(this->where == 'd' && CardsInHandAI < Cards::maxNumberCardsInHand){
         Cards::CardsInHandAI++;
         this->cardSprite.setPosition(CardsInHandAI*210, 180);
         this->where='h';
         return true;
        }
         std::cout << "Bot has too many cards in hand! He can't draw more.\n";
     return false;
    }
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

    if(this->actualTimer == 0){
     giveEffect();
     this->actualTimer = this->maxTimer;
}

}


void Artifact::loseHealth(int amount){

 this->actualHealth-=amount;
    if (this->actualHealth <= 0)this->where='g';
}


void Spell::play() {

    if(Cards::caster.getName() == "You"){
        if(Cards::caster.getActiveMana() >= this->manaCost && this->where == 'h'){
         Cards::caster.spendActiveMana(this->manaCost);
         Cards::CardsInHand--;
         this->cardSprite.setPosition(-1000,-1000);
         this->where='b';
         std::cout<<"You have played card is called " << this->name << "\n Active mana: " << Cards::caster.getActiveMana() << std::endl;
     }
     std::cout<<"You couldn't card is called " << this->name << "\n Active mana: " << Cards::caster.getActiveMana()<< std::endl;
    }

    else {
        if(Cards::caster.getActiveMana() >= this->manaCost && this->where == 'h'){
         Cards::caster.spendActiveMana(this->manaCost);
         Cards::CardsInHandAI--;
         this->cardSprite.setPosition(-1000,-1000);
         this->where='b';
         std::cout<<"Bot has played card is called " << this->name << "\n Active mana: " << Cards::caster.getActiveMana() << std::endl;
        }
        std::cout<<"Bot couldn't play card is called " << this->name << "\n Active mana: " << Cards::caster.getActiveMana()<< std::endl;
    }
}


void Weapon::play() {

    if(Cards::caster.getName() == "You"){
        if(Cards::caster.getActiveMana() >= this->manaCost && this->where == 'h'){
         Cards::caster.spendActiveMana(this->manaCost);
         Cards::CardsInHand--;
         this->cardSprite.setPosition(500,950);
         this->where='b';
         std::cout<<"You have played card is called " << this->name << "\n Active mana: " << Cards::caster.getActiveMana() << std::endl;
     }
     std::cout<<"You couldn't card is called " << this->name << "\n Active mana: " << Cards::caster.getActiveMana()<< std::endl;
    }

    else {
        if(Cards::caster.getActiveMana() >= this->manaCost && this->where == 'h'){
         Cards::caster.spendActiveMana(this->manaCost);
         Cards::CardsInHandAI--;
         this->cardSprite.setPosition(500,250);
         this->where='b';
         std::cout<<"Bot has played card is called " << this->name << "\n Active mana: " << Cards::caster.getActiveMana() << std::endl;
        }
        std::cout<<"Bot couldn't play card is called " << this->name << "\n Active mana: " << Cards::caster.getActiveMana()<< std::endl;
    }
}


void Skill::play(){

        if(Cards::caster.getName() == "You"){
        if(Cards::caster.getActiveMana() >= this->manaCost && this->where == 'h'){
         Cards::caster.spendActiveMana(this->manaCost);
         Cards::CardsInHand--;
         this->cardSprite.setPosition(-1000,-1000);
         this->where='b';
         std::cout<<"You have played card is called " << this->name << "\n Active mana: " << Cards::caster.getActiveMana() << std::endl;
     }
     std::cout<<"You couldn't card is called " << this->name << "\n Active mana: " << Cards::caster.getActiveMana()<< std::endl;
    }

    else {
        if(Cards::caster.getActiveMana() >= this->manaCost && this->where == 'h'){
         Cards::caster.spendActiveMana(this->manaCost);
         Cards::CardsInHandAI--;
         this->cardSprite.setPosition(-1000,-1000);
         this->where='b';
         std::cout<<"Bot has played card is called " << this->name << "\n Active mana: " << Cards::caster.getActiveMana() << std::endl;
        }
        std::cout<<"Bot couldn't play card is called " << this->name << "\n Active mana: " << Cards::caster.getActiveMana()<< std::endl;
    }
}


void Weapon::giveEffect(){
}

void Skill::giveEffect(){
}

Weapon::Weapon(){
 this->cardSprite.setOrigin(this->cardTexture.getSize().x/2, this->cardTexture.getSize().y/2);
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
 this->cardSprite.setOrigin(this->cardTexture.getSize().x/2, this->cardTexture.getSize().y/2);
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
 this->cardSprite.setOrigin(this->cardTexture.getSize().x/2, this->cardTexture.getSize().y/2);
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
 this->cardSprite.setOrigin(this->cardTexture.getSize().x/2, this->cardTexture.getSize().y/2);
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

    if (boundingBoxCursor.intersects(cardBoundingBox) && this->cardSprite.getScale().x < 0.9){
     this->priority = true;
     this->cardSprite.setScale(1, 1);
    }

    if(!boundingBoxCursor.intersects(cardBoundingBox))this->priority=false;

 }

if (this->priority && sf::Mouse::isButtonPressed(sf::Mouse::Left) && Cards::caster.getName() == "You"){
    play();
    }

}


void Weapon::checkStatus(){

    if (this->durability <= 0)getDestroyed();{// It zooms and unzooms cards.
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

 this->cardSprite.setOrigin(this->cardTexture.getSize().x/2, this->cardTexture.getSize().y/2);
 {// It zooms and unzooms cards.
 this->cardSprite.setScale(0.5, 0.5);

 sf::FloatRect boundingBoxCursor = Cards::cursor.getGlobalBounds();
 sf::FloatRect cardBoundingBox = this->cardSprite.getGlobalBounds();

    if(boundingBoxCursor.intersects(cardBoundingBox) && this->cardSprite.getScale().x < 0.9){
     this->cardSprite.setScale(1, 1);
     this->priority = true;
    }

    if(!boundingBoxCursor.intersects(cardBoundingBox)){
     this->priority=false;
    }

}

    if(this->priority && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
     play();
    }

}
