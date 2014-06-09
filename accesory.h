#ifndef ACCESORY_H
#define ACCESORY_H
#include "item.h"
//Accesory (rings and amulets) provide bonus to
//Magic
//Dodge
//Accuracy
class accesory: public inventory{
	public:
		accesory(std::string n, std::string d): item(n, d){}	
};
#endif
