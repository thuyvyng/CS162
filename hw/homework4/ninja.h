#include <iostream>
#include "ant.h"
#include <vector>
#include "bee.h"
using namespace std;

class Ninja: public Ant{
	public:
		string name;
		int armor;
		int location;
		int food_cost;

		Ninja();
		Ninja(const Ninja &);

		string get_name() const;
		int get_armor() const;
		int get_food_cost() const;
		void attack(vector<Ant> [], vector<Bee> [], int *, int *,int,int);

		const Ninja & operator = (const Ninja&);
		~Ninja();
};
