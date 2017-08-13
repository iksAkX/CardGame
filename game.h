#pragma once
#include <SFML/Graphics.hpp>
#include "character.h"
#include "cards.h"
#include "deck.h"


using namespace sf;

class Game
{
public:

    Deck playerDeck;
    Deck enemyDeck;

    Artifact artifact[5];
    Weapon weapon[5];
    Spell spell[5];
    Skill skill[5];

   static bool cardDrawn;

   sf::Texture heroTexture;
   sf::Sprite heroSprite;
   sf::Text yourName;

   sf::Texture enemyTexture;
   sf::Sprite enemySprite;

   sf::Texture backgroundTexture;
   sf::Sprite backgroundSprite;

   sf::Font defaultFont;
   sf::Text enemyName;

   sf::Texture endTurnTexture;
   sf::Sprite endTurnSprite;


   sf::Texture cursorTexture;
   sf::Sprite cursor;

    int cardsInEnemyDeck;
    int cardsInPlayerDeck;

   Character enemy;
   Character hero;

    Game();
    ~Game();


    void start();


private:
    void draw();                    
    void update(float);           
    void drawCard(int howMany);

    RenderWindow window;         

};
