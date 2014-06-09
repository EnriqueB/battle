#include <iostream>
#include <string.h>
#include "player.h"
#include "monster.h"
/*
char original_map[21][21];
char player_map[21][21];
void map_init(){
	memset(original_map, ' ', sizeof(original_map));
	memset(player_map, ' ', sizeof(player_map));
	//The map is read from a file;
	ifstream input;
	input.open("map.txt");
	
}
void print_map(){
legend:
@=player
M=monster
C=chest
E=exit
B=boss
	for(int i=1; i<20; i++){
		for(int j=1; j<20; j++){
			std::cout<<player_map[i][j];
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
}
*/
void character_creation(player &p){
	std::cout<<"Greetings, adventurer. What is your name?"<<std::endl;
	std::string n;
	std::cin>>n;
	p.set_name(n);
	std::cout<<"Well then, "<<p.get_name()<<" these are your starting stats\n";
	p.display();
	std::cout<<"You can rerroll your attributes if you wish to.\n";
	std::cout<<"You get three rerrolls, each being permanent\n\n";
	int cant=0;
	std::string choice ="";
	while(cant<3){
		std::cout<<"Do you wish to rerroll? Rerrolls left: "<<3-cant<<std::endl;
		std::cin>>choice;
		if(choice=="Yes" || choice == "yes"){
			p.roll();
			cant++;
			std::cout<<"Your new stats are: \n";
			p.display();
			std::cout<<std::endl<<std::endl;
		}
		else
			break;
	}
	std::cout<<"Now you have 10 attribute points to allocate. Choose wisely as you cannot undo your choices.\n";
	std::cout<<"State the name of the attribute and the ammount of points \nyou wish to allocate separated by a space\n";
	int points =0, inp;
	std::string atr;
	while(points<10){
		std::cout<<"Points left: "<<10-points<<std::endl;
		std::cin>>atr>>inp;
		if((points+inp)<=10 && inp>0){
			if(atr=="Health" || atr== "health"){
				p.set_max_health(p.get_max_health()+inp);
				p.set_curr_health(p.get_max_health());
			}
			else if(atr=="Mana" || atr=="mana"){
				p.set_max_mana(p.get_max_mana()+inp);
				p.set_curr_mana(p.get_max_mana());
			}
			else if(atr=="Attack" || atr == "attack")
				p.set_attack(p.get_attack()+inp);
			else if(atr=="Defense" || atr == "defense")
				p.set_defense(p.get_defense()+inp);	
			else if(atr=="Dodge" || atr == "dodge")
				p.set_dodge(p.get_dodge()+inp);
			else if(atr=="Accuracy" || atr == "accuracy")
				p.set_accuracy(p.get_accuracy()+inp);
			else if(atr=="Magic" || atr == "magic")
				p.set_magic(p.get_magic()+inp);
			else{
				std::cout<<"That is not an attribute\n";
				continue;
			}
			points+=inp;
		}
		else{
			std::cout<<"That is not possible, try again\n";
		}
	}
	std::cout<<"\nExcelent, these are your new attributes: \n";
	p.display();
	std::cout<<"\nNow, lets take a look at your inventory.\n";
	p.init_inventory();
	p.display_inventory();
	std::cout<<"I see you have no items equipped, why not try equipping the chest armor and the sword?\n";
	std::cout<<"Type the number of the item you want to equip: ";
	int equip;
	std::cin>>equip;
	while(equip!=1 && equip!=2){
		std::cout<<"That is not a valid item choice, please try again: ";
		std::cin>>equip;
	}
	p.equip_item(equip);
	p.display_inventory();
	std::cout<<"Type the number of the item you want to equip: ";
	std::cin>>equip;
	while(equip!=1){
		std::cout<<"That is not a valid item choice, please try again: ";
		std::cin>>equip;
	}
	p.equip_item(equip);
	p.display_inventory();
	std::cout<"Excelent, now you are ready to being your adventure!\nThis are your new stats:\n";
	p.display();
}
void menu(player &p){
	
}
int main(){
	player p;
	p.roll();
	character_creation(p);
	menu(p);
}
