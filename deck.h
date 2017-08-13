#pragma once
#include <iostream>
#include "cards.h"



class Deck {


Spell spell[5];
Skill skill[5];
Weapon weapon[5];
Artifact artifact[5];
Weapon activeWeapon;


public:

Deck();
~Deck();
void equipWeapon(Weapon &weapon);
void draw(Artifact artifact);
void draw(Weapon weapon);
void draw(Spell spell);
void draw(Skill skill);

};
