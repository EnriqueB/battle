#ifndef HELMET_H
#define HELMET_H
#include "armor.h"
class helmet: public armor{
	private:
		double magic;
		int mana;
	public:
		helmet(std::string n, std::string d, double mag, int m): armor(n, d){
			magic=mag, mana=m;
		}
		//sets
		void set_magic(double m){magic=m;}
		void set_mana(int m){mana=m;}
                //gets
                double get_magic(){return magic;}
		int get_mana(){return mana;}
		void display(){
			cout<<name<<std::endl;
			cout<<description<<std::endl;
			cout<<"Magic: "<<magic<<"\tMana: "<<mana<<std::endl;
			cout<<std::endl;
		}
		char type(){return 'E';}
		int [] get_stats(){
			int stats [7];
			memset(stats,0,7);
			stats[1]=mana;
			stats[6]=magic;
			return stats;
		}
};
#endif
