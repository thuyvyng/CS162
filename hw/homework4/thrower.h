#include <iostream>
#include <vector>
#include "ant.h"
#include "bee.h"
using namespace std;

class Thrower: public Ant{
	public:
		string name;
		int armor;
		int location;
		int food_cost;

		Thrower();
		Thrower(const Thrower &);

		string get_name() const;
		int get_armor() const;
		int get_food_cost() const;
		void attack_thrower();
		void attack(vector<Ant> [], vector<Bee> [], int *, int *,int,int);
		const Thrower & operator = (const Thrower&);
		~Thrower();
};
