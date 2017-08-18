#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Character{

 int maxHealth;
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
 static bool isEnemyTurn;

 Character();
 ~Character();

 void setCharacter(std::string name, int health, int armor, sf::Text characterName, sf::Texture characterTexture, sf::Sprite characterSprite, int activeMana, int maxMana);
 int getArmor();
 int getHealth();

 std::string getCharacterNameAsString();
 sf::Texture getCharacterTexture();
 sf::Sprite getCharacterSprite();
 sf::Text getCharacterNameAsText();
 int getActiveMana();
 int getMaxMana();
 std::string getName();
 std::string getHealthAsString();

 void setName(std::string name);
 void setTexture(std::string imageLocation);
 void setMaxHealth(int value);

 void loseHealth(int damage);
 void heal();
 void gainHealth(int amount);
 void decreaseMaxHealth(int amount);
 void increaseMaxHealth(int amount);
 void receiveArmor(int amount);
 void gainMaxMana(int amount);
 void gainActiveMana(int amount);
 void spendActiveMana(int amount);
 bool isDead();
 void equipWeapon();
 void restoreMana();
 void showStatus();

};
