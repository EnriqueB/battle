#ifndef ARMOR_H
#define ARMOR_H
#include "item.h"
//Armor (helmet, gloves, chest, legs and boots) can provide a bonus to:
//Health
//Mana
//Magic
//Dodge
//Accuracy
//Defense
class armor: public item{
	public:
		armor(std::string n, std::string d): item(n, d){}
};
#endif
