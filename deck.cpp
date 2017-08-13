#include "deck.h"
#include <cstdlib>


Deck::Deck(){

/*
artifact[0].setThis(1, "Ancient Artifact", 2, 1, 'd', "media/ancient_artifact.png", 3, 2); // done
artifact[1].setThis(2, "Supermieczyk", 1, 1, 'd', "media/cute_image.png", 2, 1);
artifact[2].setThis(3, "Supermieczyki", 1, 1, 'd', "media/cute_image.png", 2, 3);
artifact[3].setThis(4, "Supermieczydlo", 3, 1,'d', "media/cute_image.png", 2, 4);
artifact[4].setThis(5, "Supermiecz v.2.0", 3, 1, 'd', "media/cute_image.png", 4, 3);

weapon[0].setThis(6, "Stary Sztylet", 1, 0, 'd', "media/cute_image.png", 2, 2);
weapon[1].setThis(7, "åwietlisty rozpruwacz", 1, 0, 'd', "media/cute_image.png", 2, 1);
weapon[2].setThis(8, "PodrÍczna Kusza", 1, 0, 'd', "media/cute_image.png", 2, 3);
weapon[3].setThis(9, "£uk astrachaÒski", 5, 0, 'd', "media/cute_image.png", 6, 2);
weapon[4].setThis(10, "Yumi", 4, 0, 'd', "media/cute_image.png", 2, 5);

spell[0].setThis(11, "True Power", 5, 0, 'd', "media/true_power.png"); // done
spell[1].setThis(12, "Kiss of Death", 3, 2, 'd', "media/kiss_of_death.png");
spell[2].setThis(13, "Master Defence", 3, 1 , 'd', "media/master_defence.png");
spell[3].setThis(14, "Hot award", 5, 0, 'd', "media/hot_award.png");
spell[4].setThis(15, "Almighty Force", 10, 2, 'd', "media/almighty_force.png");

skill[0].setThis(16, "èrÛd≥o Many", 1, 0, 'd', "media/cute_image.png");
skill[1].setThis(17, "Moc èrÛd≥a", 1, 0, 'd', "media/cute_image.png");
skill[2].setThis(18, "Astralna Energia", 1, 0, 'd', "media/cute_image.png");
skill[3].setThis(19, "Nierealna PotÍga", 1, 0, 'd', "media/cute_image.png");
skill[4].setThis(20, "MOOOOC!", 1, 0, 'd', "media/cute_image.png");
*/

}
/*
void draw(){



    //Schemat: int wylosowana liczba = ( std::rand() % ile_liczb_w_przedziale ) + startowa_liczba;
srand( time( NULL ) );
int numberOfCardThatWillBeDrawn = ( std::rand() % 20 ) + 1;



if (numberOfCardThatWillBeDrawn <= 5)draw(artifact[numberOfCardThatWillBeDrawn].draw());
else if (numberOfCardThatWillBeDrawn <= 10 && numberOfCardThatWillBeDrawn >= 5)draw( weapon[numberOfCardThatWillBeDrawn-5].draw());
else if (numberOfCardThatWillBeDrawn <= 15 && numberOfCardThatWillBeDrawn >= 10)draw( weapon[numberOfCardThatWillBeDrawn-10].draw());
else if (numberOfCardThatWillBeDrawn <= 20 && numberOfCardThatWillBeDrawn >= 15)draw( weapon[numberOfCardThatWillBeDrawn-15].draw());

}
*/

Deck::~Deck(){

}

void Deck::draw(Artifact artifact){

artifact.draw();

}


void Deck::draw(Weapon weapon){

weapon.draw();

}

void Deck::draw(Skill skill){

skill.draw();

}


void Deck::draw(Spell spell){

spell.draw();

}

void Deck::equipWeapon(Weapon &weapon){

this->activeWeapon= weapon;
}
