#ifndef INVENTORY_H
#define INVENTORY_H
#include "item.h"
#include "equipment.h"
#include "backpack.h"
class inventory{
	private:
		backpack bp;
		equipment eq;
	public:
		inventory(){}
		bool place_in_backpack(item *it){
			return bp.place(it);			
		}
		void display_backpack(){bp.display();}
		void display_equipment(){eq.display();}
		int* get_stats(){return eq.stat_increase();}
		void equip(int number){
			item* it = bp.get_item(number);
			while(it->type()=='J' || it->type()=='K'){
				std::cout<<"Invalid type to equip. Please select another number: ";
				std::cin>>number;
				it=bp.get_item(number);
			}
			eq.equip_item(it);
		}
};

#endif
