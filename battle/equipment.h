#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include "item.h"
#include <vector>
#include <iostream>
#include <string.h>
/*
0 = health
1 = mana
2 = attack
3 = defense
4 = dodge
5 = accuracy
6 = magic
*/
class equipment{
	private:
		item* eq[9];
		int stats [7];
		bool equipped[9];
	public:
		equipment(){
			memset(stats,0,sizeof(stats));
			memset(equipped, false, sizeof(equipped));
		}
		int* stat_increase(){
			return stats;
		}
		void equip_item(item *it){
			int index = it->type()-'A';
			//already had an item equipped in that slot
			if(equipped[index]){
				//update stats array
				int* old_item_stats = eq[index]->get_stats();
				delete eq[index];
				int* new_item_stats = it->get_stats();
				for(int i=0; i< 7; i++){
					stats[i]= stats[i] - old_item_stats[i] + new_item_stats[i];
				}
				eq[index]=it;
				std::cout<<"Your new item has been equipped!\n Your old item was too worn-out to be of use\n";
			}
			//slot free
			else{
				equipped[index]=true;
				eq[index]=it;
				int *new_item_stats = it->get_stats();
				for(int i=0; i< 7; i++){
					stats[i] += new_item_stats[i];
				}
				std::cout<<"Your new item has been equipped!\n";
			}
		}
		void display(){
			int j=0;
			std::cout<<"Equipment: \n";
			for(int i=0; i<9; i++){
				if(equipped[i]){
					eq[i]->display();
					j++;
				}
			}
			if(j==0)
				std::cout<<"You have no items equipped\n";
		}
		//other stuff
};
#endif
