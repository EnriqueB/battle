#ifndef WEAPON_H
#define WEAPON_H
class weapon: public item{
	private:
		double attack;
		double accuracy;
	public:
		weapon(std::string n, std::string d, double a, double acc): item(n, d){
			attack=a, accuracy=acc;
		}
		//sets
		void set_attack(double a){attack=a;}
		void set_accuracy(double a){accuracy=a;}
		//gets
		double get_attack(){return attack;}
		double get_accuracy(){return accuracy;}
		void display(){
			std::cout<<name<<std::endl;
			std::cout<<description<<std::endl;
			std::cout<<"Attack: "<<attack<<"\tAccuracy: "<<accuracy<<std::endl;
			std::cout<<std::endl;
		}
		char type(){return 'I';}
		int* get_stats(){
			int stats [7];
			memset(stats,0,sizeof(stats));
			stats[2]=attack;
			return stats;
		}
};
#endif
