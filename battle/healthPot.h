#ifndef HEALTHPOT_H
#define HEALTHPOT_H
#include "healing.h"
#include <stdlib.h>
#include <time.h>
class health_pot: public healing{
	public:
		health_pot(std::string n, std::string d): healing(n,d){}
		double use(){
			//heals between 40 and 60% of the player's max health
			srand(time(NULL));
			return ((rand()%21+40)/100);
		}
		void display(){
			std::cout<<name<<std::endl;
			std::cout<<description<<std::endl;
			std::cout<<std::endl;
		}
		char type(){return 'J';}
};
#endif
