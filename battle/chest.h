#ifndef CHEST_H
#define CHEST_H
#include "armor.h"
class chest: public armor{
	private:
		int health;
		double defense;
	public:
		chest(std::string n, std::string d, int h, double def): armor(n, d){
			health=h, defense=def;
		}
		//sets
		void set_health(int h){health=h;}
		void set_defense(double d){defense=d;}
                //gets
		int get_health(){return health;}
		double get_defense(){return defense;}
		void display(){
			std::cout<<name<<std::endl;
			std::cout<<description<<std::endl;
			std::cout<<"Health: "<<health<<"\tDefense: "<<defense<<std::endl;
			std::cout<<std::endl;
		}
		char type (){return 'C';}
		int* get_stats(){
			int stats [7];
			memset(stats,0,sizeof(stats));
			stats[0]=health;
			stats[3]=defense;
			return stats;
		}
};
#endif
