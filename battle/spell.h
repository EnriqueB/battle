#ifndef SPELLS_H
#define SPELLS_H
class spell{
	private:
		std::string name;
		std::string description;
		double power;
		int mana_cost;
	public:
		spell(std::string n, std::string d, double p, int m){
			name=n, description=d, power=p, mana_cost=m;
		}
		//sets
		void set_name(std::string n){name=n;}
		void set_description(std::string d){description=d;}
		void set_power(double p){power=p;}
		void set_mana_cost(int m){mana_cost=m;}
		//gets
		std::string get_name(){return name;}
		std::string get_description(){return description;}
		double get_power(){return power;}
		int get_mana_cost(){return mana_cost;}
		void display(){
			std::cout<<std::endl;
			std::cout<<name<<std::endl;
			std::cout<<description<<std::endl;
			std::cout<<"Power: "<<power<<"\tMana cost: "<<mana_cost<<std::endl;
			std::cout<<std::endl;
		}	
};
#endif
