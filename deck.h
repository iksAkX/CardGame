#pragma once
#include <iostream>
#include "cards.h"

class Deck {

 int maxCardsInDeck;
 int cardsInDeck;
 Weapon activeWeapon;
 bool cardDrawn;

public:
 Weapon weapon[5];
 Spell spell[5];
 Skill skill[5];
 Artifact artifact[5];

 Deck();
 ~Deck();
 void equipWeapon(Weapon &weapon);
 void drawCard(int howMany);
 void applyTimer();
};
