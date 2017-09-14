#include "deck.h"

Deck::Deck(){

 artifact[0].setThis(1, "Ancient Artifact", 2, 1, 'd', "media/ancient_artifact.png", 3, 2); // done
 artifact[1].setThis(2, "Supermieczyk", 1, 1, 'd', "media/cute_image.png", 2, 1);
 artifact[2].setThis(3, "Supermieczyki", 1, 1, 'd', "media/cute_image.png", 2, 3);
 artifact[3].setThis(4, "Supermieczydlo", 3, 1,'d', "media/cute_image.png", 2, 4);
 artifact[4].setThis(5, "Supermiecz v.2.0", 3, 1, 'd', "media/cute_image.png", 4, 3);

 weapon[0].setThis(6, "Rusted Sword", 1, 0, 'd', "media/rusted_sword.png", 3, 1);
 weapon[1].setThis(7, "Œwietlisty rozpruwacz", 1, 0, 'd', "media/cute_image.png", 2, 1);
 weapon[2].setThis(8, "Podrêczna Kusza", 1, 0, 'd', "media/cute_image.png", 2, 3);
 weapon[3].setThis(9, "£uk astrachañski", 5, 0, 'd', "media/cute_image.png", 6, 2);
 weapon[4].setThis(10, "Yumi", 4, 0, 'd', "media/cute_image.png", 2, 5);

 spell[0].setThis(11, "True Power", 5, 0, 'd', "media/true_power.png"); // done
 spell[1].setThis(12, "Kiss of Death", 3, 2, 'd', "media/kiss_of_death.png");
 spell[2].setThis(13, "Master Defence", 3, 1 , 'd', "media/master_defence.png");
 spell[3].setThis(14, "Hot award", 5, 0, 'd', "media/hot_award.png");
 spell[4].setThis(15, "Almighty Force", 10, 2, 'd', "media/almighty_force.png");

 skill[0].setThis(16, "Aha Many", 1, 0, 'd', "media/cute_image.png");
 skill[1].setThis(17, "Power Cos Tam", 1, 0, 'd', "media/cute_image.png");
 skill[2].setThis(18, "Astralna Energia", 1, 0, 'd', "media/cute_image.png");
 skill[3].setThis(19, "Nierealna Potega", 1, 0, 'd', "media/cute_image.png");
 skill[4].setThis(20, "MOOOOC!", 1, 0, 'd', "media/cute_image.png");


 cardDrawn = false;
 maxCardsInDeck = 20;
 cardsInDeck = maxCardsInDeck;
}


Deck::~Deck(){
}


void Deck::equipWeapon(Weapon &weapon){

 this->activeWeapon = weapon;
}

void Deck::applyTimer(){

    for (int i=0;i<=4;i++){
       artifact[i].decreaseTimer();
        }

    }




void Deck::drawCard(int howMany){

 int const smallestId = 1;
 srand(time(NULL));


    for(int i=0;i<howMany;i++){
     this->cardDrawn = false;
     again:
     int numberOfCardToDraw = ( std::rand() % this->cardsInDeck ) + smallestId;

        if(cardDrawn == false && numberOfCardToDraw <= 5){
            if(artifact[numberOfCardToDraw-1].draw())cardDrawn = true;
            else std::cout <<"A card had been drawn before your current try.\n";
        }
        else if (cardDrawn==false && numberOfCardToDraw > 5 && numberOfCardToDraw <= 10 ){
            if(weapon[numberOfCardToDraw-6].draw())cardDrawn = true;
            else std::cout <<"A card had been drawn before your current try.\n";
        }
        else if (cardDrawn==false && numberOfCardToDraw > 10 && numberOfCardToDraw <= 15 ){
            if(spell[numberOfCardToDraw-11].draw())cardDrawn = true;
            else std::cout <<"A card had been drawn before your current try.\n";
        }
        else if (cardDrawn==false && numberOfCardToDraw > 15 && numberOfCardToDraw <= 20 ){
            if(skill[numberOfCardToDraw-16].draw())cardDrawn = true;
            else std::cout <<"A card had been drawn before your current try.\n";
        }
        else if (Cards::caster.getName() != "You" && cardsInDeck <= 0)std::cout << "Bot doesn't have any cards in its deck.\n";
        else if (Cards::caster.getName() == "You" && cardsInDeck <= 0)std::cout << "You don't have any cards in your deck.\n";


    if (cardDrawn==false && this->cardsInDeck > 0){
     std::cout << "Card wasn't drawn, because it wasn't in deck.\n";
     goto again;
    }


    }


}
