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

    // funkcja s�u��ca do uruchomienia gry
    void start();


private:
    void draw();                    // metoda do rysowania wszystkich obiekt�w
    void update(float);             // metoda do aktualizaowania wszystkich obiekt�w
    void drawCard();

    RenderWindow window;            // wy�wietlane okno

};
