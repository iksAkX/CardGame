#include "game.h"
#include <iostream>

Game::Game()
{
    window.create(VideoMode(1920, 1080), "Card Game", Style::Close); //1920, 1080; 1366, 768;
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);

    endTurnTexture.loadFromFile("media/end_turn_button.png");
    endTurnSprite.setTexture(endTurnTexture);
    endTurnSprite.setPosition(1500, 420);

    cursorTexture.loadFromFile("media/cursor.png");
    cursor.setTexture(cursorTexture);
    cursor.scale(0.76, 0.76);

    defaultFont.loadFromFile("media/arial.ttf");
    enemyName.setFont(defaultFont);
    enemyName.setCharacterSize(38);
    enemyName.setColor(Color(100, 200, 300));
    enemyName.setPosition(4,12);
    enemyName.setString("The Tiny Destroyer"); ////////////////////////

    backgroundTexture.loadFromFile("media/background.png");
    backgroundSprite.setTexture(backgroundTexture);

    enemyTexture.loadFromFile("media/enemyTexture.png");
    enemySprite.setTexture(enemyTexture);
    enemySprite.setOrigin(enemyTexture.getSize().x/2, enemyTexture.getSize().y/2);
    enemySprite.setPosition(930, 120);

    heroTexture.loadFromFile("media/enemyTexture.png"); //////
    heroSprite.setTexture(heroTexture);

    const std::string nameOfPlayer = "You";

    enemy.setCharacter("The little one", 30, 5, enemyName, enemyTexture, enemySprite, 1, 1);
    hero.setCharacter(nameOfPlayer, 30, 0, yourName, heroTexture, heroSprite, 1, 1); //DON'T CHANGE YOUR NAME, leave "you", it's obligatory

    enemyTurnTexture.loadFromFile("media/enemy_turn.png");

    enemyHealth.setPosition(400, 200);
    enemyHealth.setFillColor(Color::Red);
    enemyHealth.setFont(defaultFont);

    playerHealth.setPosition(1200, 800);
    playerHealth.setFillColor(Color::Red);
    playerHealth.setFont(defaultFont);
}


Game::~Game()
{
    window.close();
}


void Game::start(){

    sf::Clock clock;
    bool did = false;

    while (window.isOpen()){

     Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)window.close();
        }


 //////BEGINNING - TURN
 cursor.setPosition(static_cast<Vector2f>(Mouse::getPosition(window)));
 endTurnSprite.setColor(Color::Green);
 Cards::setCursor(cursor);
 Artifact::refreshArtifacts();
 Cards::setCharacters(hero, enemy);

 enemyHealth.setString("Enemy Health: " + hero.getHealthAsString());
 playerHealth.setString("Your Health: " + enemy.getHealthAsString());



 sf::FloatRect boundingBoxCursor = cursor.getGlobalBounds();
 sf::FloatRect endTurnBoundingBox = endTurnSprite.getGlobalBounds();
 sf::Time elapsedTime = clock.getElapsedTime();

    if(boundingBoxCursor.intersects(endTurnBoundingBox)){
       endTurnSprite.setColor(Color::Red);

        if(Mouse::isButtonPressed(Mouse::Left) && elapsedTime.asMilliseconds() >= 2500){// AI turn starts
            if (Character::isEnemyTurn==false)Character::isEnemyTurn = true;
            else if (Character::isEnemyTurn==true)Character::isEnemyTurn = false;
            clock.restart();
        }

        }
     if(Character::isEnemyTurn == true){ //enemy
        Cards::setCharacters(enemy, hero);
        endTurnSprite.setTexture(enemyTurnTexture);
        enemy.gainActiveMana(1);
        enemy.gainMaxMana(1);
        enemyDeck.drawCard(1);
        //opponent.setAI(enemyDeck, enemy);
        //opponent.chooseWhatToPlayAndDoIt();
        enemyDeck.applyTimer();
                              // dirty code below

           for (int i=0;i<=4;i++){
        if(enemyDeck.artifact[i].getWhere() == 'h' && enemy.getActiveMana() >= enemyDeck.artifact[i].getManaCost()){
         this->enemyDeck.artifact[i].play();

        }
        else if(enemyDeck.weapon[i].getWhere() == 'h' && enemy.getActiveMana() >= enemyDeck.weapon[i].getManaCost()){
         enemyDeck.weapon[i].play();
        }
        else if(enemyDeck.spell[i].getWhere() == 'h' && enemy.getActiveMana() >= enemyDeck.spell[i].getManaCost()){
         enemyDeck.spell[i].play();
        }
        else if(enemyDeck.skill[i].getWhere() == 'h' && enemy.getActiveMana() >= enemyDeck.skill[i].getManaCost()){
         enemyDeck.skill[i].play();
        }
        else std::cout << "Bot doesn't have enough mana.\n";
    }
        enemy.showStatus();
        Character::isEnemyTurn=false;
        did = false;
     }


     else if(Character::isEnemyTurn==false && elapsedTime.asMilliseconds() && did == false){ //you
        Cards::setCharacters(hero, enemy);
        endTurnSprite.setTexture(endTurnTexture);
        hero.gainActiveMana(1);
        hero.gainMaxMana(1);
        playerDeck.drawCard(1);
        playerDeck.applyTimer();
        hero.showStatus();
        did = true;
     }


 checkStatusOfCards();
 checkWhoWon();
 draw();
    }
}




void Game::draw(){
 window.clear(Color::Red);
 window.draw(backgroundSprite);

 window.draw(enemyName);
 window.draw(enemySprite);
 window.draw(endTurnSprite);
 window.draw(enemyHealth);
 window.draw(playerHealth);

 renderCards();
 renderZoomedCard();

 window.draw(cursor);
 window.display();
}


void Game::checkStatusOfCards(){

     for (int i=0;i<=4;i++){ //checking status of player's cards
       playerDeck.artifact[i].checkStatus();
       playerDeck.spell[i].checkStatus();
       playerDeck.skill[i].checkStatus();
       playerDeck.weapon[i].checkStatus();
    }

    for (int i=0;i<=4;i++){ // checking status of AI's cards
       enemyDeck.artifact[i].checkStatus();
       enemyDeck.spell[i].checkStatus();
       enemyDeck.skill[i].checkStatus();
       playerDeck.weapon[i].checkStatus();
    }
}


void Game::renderZoomedCard(){


   for (int i=0;i<=4;i++){ // setting zoom option for player
        if(playerDeck.artifact[i].getPriority()) window.draw(playerDeck.artifact[i].getSprite());
        else if(playerDeck.spell[i].getPriority()) window.draw(playerDeck.spell[i].getSprite());
        else if(playerDeck.weapon[i].getPriority())window.draw(playerDeck.weapon[i].getSprite());
        else if(playerDeck.skill[i].getPriority())window.draw(playerDeck.skill[i].getSprite());
    }

}


void Game::renderCards(){


 for (int i=0;i<=4;i++){ // rendering only card with coordinate x bigger than -100, for player
         if((playerDeck.artifact[i].getSprite().getPosition().x > - 100))window.draw(playerDeck.artifact[i].getSprite());
         if((playerDeck.spell[i].getSprite().getPosition().x > - 100)) window.draw(playerDeck.spell[i].getSprite());
         if((playerDeck.weapon[i].getSprite().getPosition().x > - 100))window.draw(playerDeck.weapon[i].getSprite());
         if((playerDeck.skill[i].getSprite().getPosition().x > - 100))window.draw(playerDeck.skill[i].getSprite());
    }

    for (int i=0;i<=4;i++){ // rendering only card with coordinate x bigger than -100, for AI
         if((enemyDeck.artifact[i].getSprite().getPosition().x > - 100)) window.draw(enemyDeck.artifact[i].getSprite());
         if((enemyDeck.spell[i].getSprite().getPosition().x > - 100)) window.draw(enemyDeck.spell[i].getSprite());
         if((enemyDeck.weapon[i].getSprite().getPosition().x > - 100))window.draw(enemyDeck.weapon[i].getSprite());
         if((enemyDeck.skill[i].getSprite().getPosition().x > - 100))window.draw(enemyDeck.skill[i].getSprite());
    }
}

void Game::checkWhoWon(){

    if (hero.isDead() && enemy.isDead()==false)std::cout<<"You lost!\n";
    else if (enemy.isDead() && hero.isDead()==false)std::cout<<"YOU WON! Your enemy lost.\n";
    else if (hero.isDead() && enemy.isDead())std::cout<<"Draw! There is no winner\n";
}

