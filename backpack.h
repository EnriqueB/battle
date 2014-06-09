#ifndef BACKPACK_H
#define BACKPACK_H
#include "item.h"
#include <vector>
#include <iostream>
class backpack{
	private:
		std::vector <item* > items;
		int capacity;
		int occupied;
	public:
		backpack(){
			//initialize vector of items
			capacity = 20;
			occupied = 0;
		}
		~backpack(){
			for(int i=0; i<occupied; i++){
				delete items[i];
				items.erase(items.begin());
			}
			occupied=0;
		}
		void display(){
			if(occupied>0){
				std::cout<<"Backpack: \n";
				int count=1;
				for(int i=0; i<items.size(); i++){
					std::cout<<"Item "<<count<<": ";
					items[i]->display();
					count++;

				}
			}
			else
				std::cout<<"Your backpack is empty.\n";
		}
		bool place(item* it){
			if(occupied<20){
				items.push_back(it);
				occupied++;
				return true;			
			}
			else{
				std::cout<<"Not enough space"<<std::endl;
				return false;
			}
		}
		item* get_item(int number){
			while(number<1 || number>occupied){
				std::cout<<"That is not a valid item number. Please try again: ";
				std::cin>>number;
			}
			item* temp = items[--number];
			items.erase(items.begin()+number);
			return temp;
		}
		//stuff
};
#endif
