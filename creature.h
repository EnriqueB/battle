#ifndef CREATURE_H
#define CREATURE_H
#include <string>
#include "item.h"
class creature{
	protected:
		int max_health;
		int curr_health;
		int max_mana;
		int curr_mana;
		double attack;
		double defense;
		double dodge;		//% of chance to dodge an attack
		double accuracy;	//% of chance to hit an attack
		double magic;
		//vector of spells
		double level;
		std::string name;
	public:
		creature(){}
		creature(int h, int m, double a, double def, double dod, 
			double acc, double mag, std::string n){
			max_health=curr_health=h, max_mana=curr_mana=m, attack=a, defense=def, dodge=dod, accuracy=acc;
			magic=mag, level=1, name=n;
			//initialize spell vector
		}
		//sets
		void set_max_health(int h){max_health=h;}
		void set_curr_health(int h){ curr_health=h;}
		void set_max_mana(int m){max_mana=m;}
		void set_curr_mana(int m){curr_mana=m;}
		void set_attack(double a){attack=a;}
		void set_defense(double d){defense=d;}
		void set_dodge(double d){dodge=d;}
		void set_accuracy(double a){accuracy=a;}
		void set_magic(double m){magic=m;}
		void set_name(std::string n){name=n;}
		//gets
		int get_max_health(){return max_health;}
		int get_curr_health(){return curr_health;}
		int get_max_mana(){return max_mana;}
		int get_curr_mana(){return curr_mana;}
		double get_attack(){return attack;}
		double get_defense(){return defense;}
		double get_dodge(){return dodge;}
		double get_accuracy(){return accuracy;}
		double get_magic(){return magic;}
		//getSpells()
		double get_level(){return level;}
		std::string get_name(){return name;}
		//class methods
		void display(){
			std::cout<<"Health: "<<curr_health<<"/"<<max_health<<std::endl;
        		std::cout<<"Mana: "<<curr_mana<<"/"<<max_mana<<std::endl;
        		std::cout<<"Attack: "<<attack<<std::endl;
        		std::cout<<"Defense: "<<defense<<std::endl;
        		std::cout<<"Dodge: "<<dodge<<std::endl;
        		std::cout<<"Accuracy: "<<accuracy<<std::endl;
        		std::cout<<"Magic: "<<magic<<std::endl;
        		std::cout<<"Level: "<<level<<std::endl;
		}
};
#endif
