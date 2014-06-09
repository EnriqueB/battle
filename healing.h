#ifndef HEALING_H
#define HEALING_H
#include "item.h"
//Healing items are health pots and mana pots
class healing: public item{
	public:
		healing(std::string n, std::string d): item(n,d){}
};
#endif
