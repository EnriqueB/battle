#ifndef ITEM_H
#define ITEM_H
class item{
	protected:
		std::string name;
		std::string description;
	public:
		item(){}
		item(std::string n, std::string d){name=n, description=d;}
		//sets
		void set_mame(std::string n){name=n;}
		void set_description(std::string d){description=d;}
		//gets
		virtual std::string get_name(){return name;}
		virtual std::string get_description(){return description;}
		virtual char type(){}
		virtual int* get_stats(){}
		virtual void display(){}
};
#endif
