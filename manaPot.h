#ifndef MANAPOT_H
#define MANAPOT_H
#include "healing.h"
#include <stdlib.h>
#include <time.h>
class mana_pot: public healing{
	public:
		mana_pot(std::string n, std::string d): healing(n,d){}
		double use(){
			//heals between 40 and 60% of the player's max mana
			srand(time(NULL));
			return ((rand()%21+40)/100);
		}
		void display(){
			std::cout<<name<<std::endl;
			std::cout<<description<<std::endl;
			std::cout<<std::endl;
		}
		char type(){return 'K';}
};
#endif
