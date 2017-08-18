#pragma once
#include <SFML/Graphics.hpp>
#include "character.h"
#include "cards.h"
#include "deck.h"
#include <cstdlib>

using namespace sf;

class Game
{

public:
 Deck playerDeck;
 Deck enemyDeck;

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
 sf::Texture enemyTurnTexture;

 sf::Texture cursorTexture;
 sf::Sprite cursor;

 sf::Text enemyHealth;
 sf::Text playerHealth;

 Character enemy;
 Character hero;

 bool enemyTurn = false;

 Game();
 ~Game();
 void start();

private:
    void draw();
    void checkStatusOfCards();
    void renderZoomedCard();
    void renderCards();
    void checkWhoWon();

    RenderWindow window;

};
