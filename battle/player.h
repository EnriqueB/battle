#ifndef PLAYER_H
#define PLAYER_H
//#include "inventory.h"
#include "creature.h"
#include "spell.h"
#include "item.h"
#include "inventory.h"
#include "chest.h"
#include "weapon.h"
#include "healthPot.h"
#include "manaPot.h"
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
class player: public creature{
	private:
		inventory inv;
		int x;
		int y;
		std::vector<spell> spells;
	public:
		player() : creature(){
			level = 1;
			x=9;
			y=19;
		}
		//sets
		void set_pos_x(int p){x=p;}
		void set_pos_y(int p){y=p;}
		//gets
		int get_pos_x(){return x;}
		int get_pos_y(){return y;}
		//class methods
		void roll(){
                        max_health=curr_health=100, max_mana=curr_mana=50, attack=20;
			defense=10, dodge=8, accuracy=80, magic=10, level=1;
                        srand(time(NULL));
                        max_health+=rand()%31-15;
			curr_health=max_health;
                        max_mana+=rand()%31-15;
			curr_mana=max_mana;
                        attack+=rand()%11-5;
                        defense+=rand()%7-3;
                        dodge+=rand()%7-3;
                        accuracy+=rand()%11-5;
                        magic+=rand()%7-3;
                }
		void init_inventory(){
			//gives initial items to the players inventory
			//chest
			chest* c = new chest("Leather chest armor", "A simple chest armor made of leather.", 5, 5);
			weapon* w = new weapon("Wooden sword", "A simple sword, made out of wood.", 5, 3);
			health_pot* h = new health_pot("Healing potion", "This potion will restore a portion of your maximum health.");
			mana_pot* m = new mana_pot("Mana potion", "This potion will restore a portion of your maximum mana.");
			item* i = c;
			bool x=inv.place_in_backpack(i);
			i=w;
			x=inv.place_in_backpack(i);
			i=h;
			x=inv.place_in_backpack(i);
			i=m;			
			x=inv.place_in_backpack(i);
		}
		void display_inventory(){inv.display_equipment(); inv.display_backpack();}
		bool add_item(item *it){return inv.place_in_backpack(it);}
		void display(){
			int* stats = inv.get_stats();
			std::cout<<"Health: "<<curr_health<<"/"<<max_health+stats[0]<<std::endl;
        		std::cout<<"Mana: "<<curr_mana<<"/"<<max_mana+stats[1]<<std::endl;
        		std::cout<<"Attack: "<<attack+stats[2]<<std::endl;
        		std::cout<<"Defense: "<<defense+stats[3]<<std::endl;
        		std::cout<<"Dodge: "<<dodge+stats[4]<<std::endl;
        		std::cout<<"Accuracy: "<<accuracy+stats[5]<<std::endl;
        		std::cout<<"Magic: "<<magic+stats[6]<<std::endl;
        		std::cout<<"Level: "<<level<<std::endl;
		}
		void equip_item(int number){
			inv.equip(number);
		}
};
#endif
