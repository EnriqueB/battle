#include <iostream>
#include <fstream>
#include <string.h>
#include "player.h"
#include "monster.h"
//list of methods
void chart_player_map(player &p);
void print_map();

char original_map[21][21];
char player_map[21][21];
void map_init(player &p){
	memset(original_map, '.', 21*21*sizeof(original_map[0][0]));
	memset(player_map, '.', 21*21*sizeof(player_map[0][0]));
	//The map is read from a file
	std::ifstream input ("map.txt");
	std::string inp="";
	int i=1;
	while(std::getline(input, inp)){
		for(int j=1; j<20; j++){
			original_map[i][j]=inp[j-1];	
		}
		i++;
	}
	original_map[20][9]='#';
	chart_player_map(p);	
}
void print_map(){
/*
legend:
@=player
M=monster
C=chest
E=exit
B=boss
*/
	for(int i=1; i<20; i++){
		for(int j=1; j<20; j++){
			std::cout<<player_map[i][j];
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl<<std::endl;
}
//this method updates the player's map after every move
void chart_player_map(player &p){
	int x = p.get_pos_x();
	int y = p.get_pos_y();
	player_map[y][x]='@';
	player_map[y-1][x-1]=original_map[y-1][x-1];
	player_map[y][x-1]=original_map[y][x-1];
	player_map[y-1][x]=original_map[y-1][x];
	player_map[y+1][x-1]=original_map[y+1][x-1];
	player_map[y-1][x+1]=original_map[y-1][x+1];
	player_map[y+1][x]=original_map[y+1][x];
	player_map[y][x+1]=original_map[y][x+1];
	player_map[y+1][x+1]=original_map[y+1][x+1];
}
void character_creation(player &p){
	std::cout<<"Greetings, adventurer. What is your name?"<<std::endl;
	std::string n;
	std::cin>>n;
	p.set_name(n);
	std::cout<<"Well then, "<<p.get_name()<<" these are your starting stats\n";
	p.display();
	std::cout<<"You can reroll your attributes if you wish to.\n";
	std::cout<<"You get three rerolls, each being permanent\n\n";
	int cant=0;
	std::string choice ="";
	while(cant<3){
		std::cout<<"Do you wish to reroll? Rerrolls left: "<<3-cant<<std::endl;
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
	map_init(p);
	std::cout<<"Before you go, take a look at your map.\nYou can move either north, west, east and south.\n";
	std::cout<<"# represents a wall, @ represents yourself, M represents a monster,\n";
	std::cout<<"C represents a chest, a '.' represents an area you have not explored\n"; 
	std::cout<<"and finally, B represents the boss that you will have to beat in order to escape.\nMay the Gods be with you.\n\n";
}
void option_1(player &p){
	int direction;
	std::cout<<"Pick your direction: \n";
	std::cout<<"1.- North\n";
	std::cout<<"2.- West\n";
	std::cout<<"3.- South\n";
	std::cout<<"4.- East\n";
	std::cin>>direction;
	switch(direction){
		case 1:
			if(original_map[p.get_pos_y()-1][p.get_pos_x()]!='#'){
				p.set_pos_y(p.get_pos_y()-1);
				chart_player_map(p);
			}
			else{
				std::cout<<"\n\nThat is not possible\n";
			}
			break;
		case 2:
			if(original_map[p.get_pos_y()][p.get_pos_x()-1]!='#'){
				p.set_pos_x(p.get_pos_x()-1);
				chart_player_map(p);
			}
			else{
				std::cout<<"\n\nThat is not possible\n";
			}
			break;
		case 3:
			if(original_map[p.get_pos_y()+1][p.get_pos_x()]!='#'){
				p.set_pos_y(p.get_pos_y()+1);
				chart_player_map(p);
			}
			else{
				std::cout<<"\n\nThat is not possible\n";
			}
			break;
		case 4:
			if(original_map[p.get_pos_y()][p.get_pos_x()+1]!='#'){
				p.set_pos_x(p.get_pos_x()+1);
				chart_player_map(p);
			}
			else{
				std::cout<<"\n\nThat is not possible\n";
			}
			break;
		default:
			std::cout<<"That is not a valid option\n";
			break;
	}
}
void menu(player &p){
	bool menu = true;
	while(menu){
		print_map();
		std::cout<<"What will you do?\n";
		std::cout<<"1.- Move\n";
		std::cout<<"2.- Look at your inventory\n";
		std::cout<<"3.- Look at the map again\n";
		std::cout<<"4.- Save and quit\n";
		int decision;
		std::cin>>decision;
		switch(decision){
			case 1:
				option_1(p);
				break;
			case 2:
			//	option_2(p);
				break;
			case 3:
				print_map();
				break;
			case 4:
				menu=false;
				std::cout<<"\n";
				break;
			default:
				std::cout<<"That is not a valid option. Please try again \n";
				break;
		}
	}
}
int main(){
	player p;
	p.roll();
	character_creation(p);
	menu(p);
}
