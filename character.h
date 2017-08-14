#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>



class Character{


int initialHealth;
int initialArmor;
sf::Texture characterTexture;
sf::Text characterName;
sf::Sprite characterSprite;
std::string name;
int health;
int armor;
int maxMana;
int activeMana;



public:
Character();
~Character();

    void setCharacter(std::string name, int health, int armor, sf::Text characterName, sf::Texture characterTexture, sf::Sprite characterSprite, int activeMana, int maxMana);

int getArmor();

int getHealth();

std::string getCharacterNameAsString();

sf::Texture getCharacterTexture();

sf::Sprite getCharacterSprite();

sf::Text getCharacterNameAsText();

void loseHealth(int damage);

void changeName(std::string name);

void changeTexture(std::string imageLocation);

void heal();

void gainHealth(int amount);

void setInitalHealth(int value);

void decreaseInitialHealth(int amount);

void receiveArmor(int amount);

void gainMaxMana(int amount);

void gainActiveMana(int amount);

void spendActiveMana(int amount);

bool isDead();

void equipWeapon();

int getActiveMana();

int getMaxMana();



};
