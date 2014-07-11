#ifndef AMULET_H
#define AMULET_H
#include "accesory.h"
class amulet: public accesory{
	private
		double magic;
		double dodge;
		double accuracy;
	public:
		amulet(std::string n, std::string d, double m, double dod, double a): accesory(n, d, m, dod, a){
			magic=m, dodge=dod, accuracy=a;
		}
		//sets
		void set_magic(double m){magic=m;}
		void set_dodge(double d){dodge=d;}
		void set_accuracy(double a){accuracy=a;}
		//gets
		double get_magic(){return magic;}
		double get_dodge(){return dodge;}
		double get_accuracy(){return accuracy;}
		void display(){
			cout<<name<<std::endl;
			cout<<description<<std::endl;
			cout<<"Dodge: "<<dodge<<"\tAccuracy: "<<accuracy<<"\tMagic: "<<magic<<std::endl;
			cout<<std::endl;
		}
		char type(){return 'A';}
		int [] get_stats(){
			int stats [7];
			memset(stats,0,7);
			stats[4]=dodge;
			stats[5]=accuracy;
			stats[6]=magic;
			return stats;
		}
};
#endif
