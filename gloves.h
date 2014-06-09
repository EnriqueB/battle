#ifndef GLOVES_H
#define GLOVES_H
#include "armor.h"
class gloves: public armor{
	private:
		double accuracy;
		int health;
	public
		gloves(std::string n, std::string d, int h, double a): armor(n, d){
			accuracy=a, health=h;		
		}
		//sets
		void set_health(int h){health=h;}
                void set_accuracy(double a){accuracy=a;}
                //gets
		double get_health(){return health;}
                double get_accuracy(){return accuracy;}
		void display(){
			cout<<name<<std::endl;
			cout<<description<<std::endl;
			cout<<"Health: "<<health<<"\tAccuracy: "<<accuracy<<std::endl;
			cout<<std::endl;
		}
		char type(){return 'D';}
		int [] get_stats(){
			int stats [7];
			memset(stats,0,7);
			stats[0]=health;
			stats[5]=accuracy;
			return stats;
		}
};
#endif
