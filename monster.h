#ifndef MONSTER_H
#define MONSTER_H
#include "creature.h"
class monster: public creature{
	private:
		//loot vector
	public:
		monster(int h, int m, double a, double def, double dod, double acc, 
			double mag, std::string n) : creature(h, m, a, def, dod, acc, mag, n){}
		//add item to loot vector
		//get loot vector
};
#endif
