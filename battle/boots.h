#ifndef BOOTS_H
#define BOOTS_H
#include "armor.h"
#include <iostream>
class boots: public armor{
	private:
		double dodge;
		double accuracy
	public
		boots(std::string n, std::string d, double dod, double a): armor(n, d){
			dodge=dod, accuracy=a;		
		}
		//sets
		void set_dodge(double d){dodge=d;}
                void set_accuracy(double a){accuracy=a;}
                //gets
		double get_dodge(){return dodge;}
                double get_accuracy(){return accuracy;}
		void display(){
			cout<<name<<std::endl;
			cout<<description<<std::endl;
			cout<<"Dodge: "<<dodge<<"\tAccuracy: "<<accuracy<<std::endl;
			cout<<std::endl;
		}
		char type(){return 'B';}
		int [] get_stats(){
			int stats [7];
			memset(stats,0,7);
			stats[4]=dodge;
			stats[5]=accuracy;
			return stats;
		}
};
#endif
