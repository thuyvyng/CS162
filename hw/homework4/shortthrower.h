#include <iostream>
#include "ant.h"
#include <vector>
#include "bee.h"
using namespace std;

class ShortThrower: public Ant{
	public:
		string name;
		int armor;
		int location;
		int food_cost;

		ShortThrower();
		ShortThrower(const ShortThrower &);

		string get_name() const;
		int get_armor() const;
		int get_food_cost() const;

		void attack(vector<Ant> [], vector<Bee> [], int *, int *,int,int);

		const ShortThrower & operator = (const ShortThrower&);
		~ShortThrower();
};
