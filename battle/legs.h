#ifndef LEGS_H
#define LEGS_H
#include "armor.h"
class legs: public armor{
	private:
		double dodge;
		int health;
	public
		legs(std::string n, std::string d, int h, double dod): armor(n, d){
			dodge=dod, health=h;		
		}
		//sets
		void set_health(int h){health=h;}
                void set_dodge(double d){dodge=d;}
                //gets
		int get_health(){return health;}
                double get_dodge(){return dodge;}
		void display(){
			cout<<name<<std::endl;
			cout<<description<<std::endl;
			cout<<"Dodge: "<<dodge<<"\tHealth: "<<health<<std::endl;
			cout<<std::endl;
		}
		char type(){return 'F';}
		int [] get_stats(){
			int stats [7];
			memset(stats,0,7);
			stats[0]=health;
			stats[4]=dodge;
			return stats;
		}
};
#endif
