#ifndef SHIELD_H
#define SHIELD_H
#include "item.h"
class weapon: public item{
	private:
		double defense;
	public:
		shield(std::string n, std::string d, double def): item(n, d){
			defense=def
		}
		//sets
		void set_defense(double d){defense=d;}
		//gets
		double get_defense(){return defense;}
		void display(){
			cout<<name<<std::endl;
			cout<<description<<std::endl;
			cout<<"Defense: "<<defense<<std::endl;
			cout<<std::endl;
		}
		char type(){return 'H';}
		int [] get_stats(){
			int stats [7];
			memset(stats,0,7);
			stats[3]=defense;
			return stats;
		}
};
#endif
