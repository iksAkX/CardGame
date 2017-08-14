#include "game.h"
#include <iostream>

bool Game::cardDrawn = false;

Game::Game()
{
    window.create(VideoMode(1920, 1080), "Card Game", Style::Close);
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

   heroTexture.loadFromFile("media/"); //////
   heroSprite.setTexture(heroTexture);

    Game::cardDrawn = false;


   enemy.setCharacter("The little one", 30, 5, enemyName, enemyTexture, enemySprite, 1, 1);
   hero.setCharacter("You", 30, 0, yourName, heroTexture, heroSprite, 1, 1);


    cardsInEnemyDeck = 20;
   cardsInPlayerDeck = 20;



artifact[0].setThis(1, "Ancient Artifact", 2, 1, 'd', "media/ancient_artifact.png", 3, 2); // done
artifact[1].setThis(2, "Supermieczyk", 1, 1, 'd', "media/cute_image.png", 2, 1);
artifact[2].setThis(3, "Supermieczyki", 1, 1, 'd', "media/cute_image.png", 2, 3);
artifact[3].setThis(4, "Supermieczydlo", 3, 1,'d', "media/cute_image.png", 2, 4);
artifact[4].setThis(5, "Supermiecz v.2.0", 3, 1, 'd', "media/cute_image.png", 4, 3);

weapon[0].setThis(6, "Stary Sztylet", 1, 0, 'd', "media/cute_image.png", 2, 2);
weapon[1].setThis(7, "Świetlisty rozpruwacz", 1, 0, 'd', "media/cute_image.png", 2, 1);
weapon[2].setThis(8, "Podręczna Kusza", 1, 0, 'd', "media/cute_image.png", 2, 3);
weapon[3].setThis(9, "Łuk astrachański", 5, 0, 'd', "media/cute_image.png", 6, 2);
weapon[4].setThis(10, "Yumi", 4, 0, 'd', "media/cute_image.png", 2, 5);

spell[0].setThis(11, "True Power", 5, 0, 'd', "media/true_power.png"); // done
spell[1].setThis(12, "Kiss of Death", 3, 2, 'd', "media/kiss_of_death.png");
spell[2].setThis(13, "Master Defence", 3, 1 , 'd', "media/master_defence.png");
spell[3].setThis(14, "Hot award", 5, 0, 'd', "media/hot_award.png");
spell[4].setThis(15, "Almighty Force", 10, 2, 'd', "media/almighty_force.png");

skill[0].setThis(16, "Źródło Many", 1, 0, 'd', "media/cute_image.png");
skill[1].setThis(17, "Moc Źródła", 1, 0, 'd', "media/cute_image.png");
skill[2].setThis(18, "Astralna Energia", 1, 0, 'd', "media/cute_image.png");
skill[3].setThis(19, "Nierealna Potęga", 1, 0, 'd', "media/cute_image.png");
skill[4].setThis(20, "MOOOOC!", 1, 0, 'd', "media/cute_image.png");

Cards::setCharacters(hero, enemy);



}


Game::~Game()
{
    window.close();
}




void Game::start()
{

sf::Clock clock;
bool rightButtonReleased;



    while (window.isOpen())
    {
        rightButtonReleased=false;
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

                if (event.type == sf::Event::MouseButtonReleased){
                    if (event.mouseButton.button == sf::Mouse::Right)rightButtonReleased=true;
                }
        }


cursor.setPosition(static_cast<Vector2f>(Mouse::getPosition(window)));

endTurnSprite.setColor(Color::Green);

        //////BEGINNING - TURN



sf::FloatRect boundingBoxCursor = cursor.getGlobalBounds();
sf::FloatRect endTurnBoundingBox = endTurnSprite.getGlobalBounds();
sf::Time timeFromCardDrawn = clock.getElapsedTime();



if (boundingBoxCursor.intersects(endTurnBoundingBox))
{
       endTurnSprite.setColor(Color::Red);

    if ( Mouse::isButtonPressed(Mouse::Left) && timeFromCardDrawn.asMilliseconds() > 200){//

    drawCard(1);
    clock.restart();
    }
}







Cards::setCursor(cursor);
Artifact::refreshArtifacts();

     for (int i=0;i<=4;i++){
       artifact[i].checkStatus();
       spell[i].checkStatus();
       skill[i].checkStatus();
       weapon[i].checkStatus();
    }
        /////END - TURN, pressing key will start new turn and end this one,

        ////

        if (hero.isDead() && enemy.isDead()==false)std::cout<<"You lost!\n";
       else if (enemy.isDead() && hero.isDead()==false)std::cout<<"Your enemy lost!\n";
       else if (hero.isDead() && enemy.isDead())std::cout<<"Draw!\n";



        draw();
    }

}






void Game::draw()
{


    window.clear(Color::Red);


  window.draw(backgroundSprite);


    for (int i=0;i<=4;i++){ // rendering only card with coordinate x bigger than -100
       if((artifact[i].getSprite().getPosition().x > - 100)) window.draw(artifact[i].getSprite());
        if((spell[i].getSprite().getPosition().x > - 100)) window.draw(spell[i].getSprite());
         if((weapon[i].getSprite().getPosition().x > - 100))window.draw(weapon[i].getSprite());
         if((skill[i].getSprite().getPosition().x > - 100))window.draw(skill[i].getSprite());
    }

    window.draw(artifact[0].getSprite());
    window.draw( spell[1].getSprite());


    window.draw(enemyName);

    window.draw(enemySprite);

    window.draw(endTurnSprite);

  for (int i=0;i<=4;i++){ // rendering only card with coordinate x bigger than -100
       if(artifact[i].getPriority()) window.draw(artifact[i].getSprite());
        if(spell[i].getPriority()) window.draw(spell[i].getSprite());
         if(weapon[i].getPriority())window.draw(weapon[i].getSprite());
         if(skill[i].getPriority())window.draw(skill[i].getSprite());
    }

    window.draw(cursor);
    window.display();
}

void Game::drawCard(int howMany){


int numberOfCardsInDeck = cardsInPlayerDeck; // until this and this one below will be correct, all should work correctly
int smallestId = 1;

int repeats = 0;


srand( time( NULL ) );

for (int i=0;i<=howMany-1;i++){
    Game::cardDrawn = false;
      int numberOfCardThatWillBeDrawn = ( std::rand() % numberOfCardsInDeck ) + smallestId;
again:


repeats++;



if (numberOfCardThatWillBeDrawn <= 5 &&  artifact[numberOfCardThatWillBeDrawn].draw() && Game::cardDrawn == false ){ std::cout << artifact[numberOfCardThatWillBeDrawn].getId() << std::endl; Game::cardDrawn = true; }
else if (numberOfCardThatWillBeDrawn <= 10 && numberOfCardThatWillBeDrawn >= 5 && weapon[numberOfCardThatWillBeDrawn-5].draw() && Game::cardDrawn == false){ std::cout << artifact[numberOfCardThatWillBeDrawn-5].getId() << std::endl; Game::cardDrawn = true; }
else if (numberOfCardThatWillBeDrawn <= 15 && numberOfCardThatWillBeDrawn >= 10 && spell[numberOfCardThatWillBeDrawn-10].draw() && Game::cardDrawn == false){ std::cout << spell[numberOfCardThatWillBeDrawn-10].getId() << std::endl; Game::cardDrawn = true;}
else if (numberOfCardThatWillBeDrawn <= 20 && numberOfCardThatWillBeDrawn >= 15 && skill[numberOfCardThatWillBeDrawn-15].draw() && Game::cardDrawn == false){  std::cout << skill[numberOfCardThatWillBeDrawn-15].getId() << std::endl; Game::cardDrawn = true;}

if(repeats <= 20){
    goto again;
cardsInPlayerDeck--;
}
 else std::cout << "Card cannot be drawn, deck is empty."  << std::endl;

}



}
