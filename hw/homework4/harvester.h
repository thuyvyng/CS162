#include <iostream>
#include "ant.h"
using namespace std;

class Harvester: public Ant{
	public:
		string name;
		int armor;
		int location;
		int food_cost;

		Harvester();
		Harvester(const Harvester &);

		string get_name() const;
		int get_armor() const;
		int get_food_cost() const;
		int attack_Harvester();
		const Harvester & operator = (const Harvester&);
		~Harvester();
};
