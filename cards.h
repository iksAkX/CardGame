#pragma once
#include <SFML/Graphics.hpp>
#include "character.h"

class Cards{

protected:
int id;
std::string name;
int manaCost;
int rarity; // 0 - common, 1 - uncommon, 2 - rare, 3 - legendary, 4 - mythic legendary
char where; // d - in deck, h - in hand, b - on battlefield, g - out of the game, graveyard


sf::Texture cardTexture;
sf::Sprite cardSprite;
bool priority;


public:
//Cards(std::string whereIsTexture);
//~Cards();
static Character opponent;
static Character caster;

static int CardsInHand;
static int CardsOnBattlefield;
static sf::Sprite cursor;
static void setCursor(sf::Sprite &cursorReference);
static void setCharacters(Character &caster, Character &opponent);

int getId();
sf::Sprite getSprite();
void setPosition(float x, float y); // it uses SFML method setPosition();
void changePosition(float x, float y); // it uses another method - move();
void checkStatus(); // old arguments: sf::Sprite &cursor
bool getPriority();


void discard();

virtual void play()=0;

virtual void giveEffect()=0;

};

class Artifact: public Cards{ // they are put onto the battlefield, their effect active when timer shows 0, it

int maxTimer;
int actualTimer;
int maxHealth;
int actualHealth;

public:

    static bool areAllDestroyed;
    static void refreshArtifacts();

Artifact();
void play();
void decreaseTimer();
void loseHealth(int amount);
void giveEffect();
void getDestroyed();

void checkStatus(); // you need to use this after each action, strange :/ old arguments: sf::Sprite &cursor


bool draw();
void setThis(int id, std::string name, int manaCost, int rarity, char where, std::string whereIsTexture, int maxTimer, int maxHealth);

};


class Spell: public Cards{ // these give you effect for mana, they go out of the game after being played

public:

Spell();
virtual void play();
virtual void giveEffect();
bool draw();

void setThis(int id, std::string name, int manaCost, int rarity, char where, std::string whereIsTexture);
};


class Weapon: public Cards{ // you can attack with them

int durability;
int attack;


public:

Weapon();
virtual void play();
virtual void giveEffect();
bool draw();
void getDestroyed();

void checkStatus();

void setThis(int id, std::string name, int manaCost, int rarity, char where, std::string whereIsTexture, int attack, int durability);
};


class Skill: public Cards{ // those cards give you mana

int manaNumber;

public:
Skill();
virtual void play();
virtual void giveEffect();
bool draw();

void setThis(int id, std::string name, int manaCost, int rarity, char where, std::string whereIsTexture);
};

